#include "graph.h"
#include <algorithm>

Graph::Graph(SDL_Renderer *renderer, SortMeasurement data[], int n, char *title)
	: renderer(renderer), n(n), columnCount(10), rowCount(10), unitW(10), unitH(10), unitScale(1), title(title)
{
	this->data = new SortMeasurement[n];
	std::copy(data, data + n, this->data);

	maxDataX = 0;
	maxDataY = 0;
	for (int i = 0; i < n; i++)
	{
		if (data[i].inputSize > maxDataX)
		{
			maxDataX = data[i].inputSize;
		}
		if (data[i].time > maxDataY)
		{
			maxDataY = data[i].time;
		}
	}

	int sigX = 1;
	while (maxDataX > 100)
	{
		maxDataX /= 10;
		sigX *= 10;
	}

	maxDataX++;
	maxDataX *= sigX;

	int sigY = 1;
	while (maxDataY > 100)
	{
		maxDataY /= 10;
		sigY *= 10;
	}

	maxDataY++;
	maxDataY *= sigY;

	displayArea = {0, 0, 0, 0};

	font = TTF_OpenFont("Roboto-Regular.ttf", 10);
	if (!font)
	{
		std::cerr << "Font Loading Error: " << TTF_GetError() << std::endl;
	}
}

Graph::~Graph()
{
	delete[] data; // Free allocated data array
}

SortMeasurement *Graph::getData()
{
	SortMeasurement *d = new SortMeasurement[n];
	std::copy(data, data + n, d);
	return d;
}

void Graph::setXpos(int x) { displayArea.x = x; }

void Graph::setYpos(int y) { displayArea.y = y; }

void Graph::setWidth(int w)
{
	displayArea.w = w;
	unitW = displayArea.w / columnCount;
	updateDeltaX();
}

void Graph::setHeight(int h)
{
	displayArea.h = h;
	unitH = displayArea.h / rowCount;
	updateDeltaY();
}

void Graph::setUnitScale(int s)
{
	unitScale = s;
}

void Graph::updateDeltaX()
{

	if (maxDataX > 0)
	{
		deltaX = maxDataX / columnCount;
	}
	else
	{
		deltaX = 1;
	}
}

void Graph::updateDeltaY()
{
	if (maxDataY > 0)
	{
		deltaY = maxDataY / rowCount;
	}
	else
	{
		deltaY = 1;
	}
}

void Graph::drawLabel(const std::string &label, int x, int y, double xOffset, double yOffset)
{
	SDL_Surface *surface = TTF_RenderText_Solid(font, label.c_str(), textColor);
	if (surface)
	{
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (texture)
		{
			int width = surface->w;
			int height = surface->h;
			SDL_Rect dstrect = {x + (width * xOffset), y + (height * yOffset), width, height};
			SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
			SDL_DestroyTexture(texture);
		}
		SDL_FreeSurface(surface);
	}
}

void Graph::draw()
{
	SDL_SetRenderDrawColor(renderer, graphColor.r, graphColor.g, graphColor.b, graphColor.a);

	// Draw X Grid Lines
	for (int i = 0; i <= columnCount; i++)
	{
		int x = displayArea.x + i * unitW * unitScale;
		SDL_RenderDrawLine(renderer, x, displayArea.y, x, displayArea.y + displayArea.h);

		// Draw X labels
		if (i % (columnCount / 5) == 0)
		{
			std::string label = std::to_string(i * deltaX);
			drawLabel(label, x, displayArea.y + displayArea.h, -0.5, 0);
		}
	}

	// Draw Y Grid Lines
	for (int i = 0; i < rowCount; i++)
	{
		int y = displayArea.y + i * unitH * unitScale;
		SDL_RenderDrawLine(renderer, displayArea.x, y, displayArea.x + displayArea.w, y);

		// Draw Y labels
		if (i % (rowCount / 5) == 0)
		{
			std::string label = std::to_string((rowCount - i) * deltaY);
			drawLabel(label, displayArea.x, y, -1, -0.5);
		}
	}

	// Draw Data Points
	SDL_Point *points = new SDL_Point[n];
	for (int i = 0; i < n; i++)
	{
		points[i].x = displayArea.x + (data[i].inputSize * unitW * unitScale / deltaX);
		points[i].y = displayArea.y + displayArea.h - (data[i].time * unitH * unitScale / deltaY);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	// SDL_RenderDrawPoints(renderer, points, n);
	SDL_RenderDrawLines(renderer, points, n);

	// Draw Axis
	SDL_SetRenderDrawColor(renderer, graphColor.r, graphColor.g, graphColor.b, graphColor.a);
	SDL_RenderDrawLine(renderer, displayArea.x, displayArea.y + displayArea.h, displayArea.x + displayArea.w, displayArea.y + displayArea.h); // X Axis
	SDL_RenderDrawLine(renderer, displayArea.x, displayArea.y + displayArea.h, displayArea.x, displayArea.y);								  // Y Axis

	drawLabel(title, displayArea.x + displayArea.w / 2, displayArea.y, -0.5, -1);

	delete[] points;
	SDL_RenderPresent(renderer);
}
