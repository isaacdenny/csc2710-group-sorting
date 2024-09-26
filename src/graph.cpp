#include "graph.h"

Graph::Graph(SDL_Renderer *renderer, SortMeasurement data[], int n) : renderer(renderer), displayArea(), n(n), columnCount(10), rowCount(10), unitW(10), unitH(10), unitScale(1), deltaX(1), deltaY(1)
{
	this->data = new SortMeasurement[n];
	for (int i = 0; i < n; i++)
	{
		this->data[i] = data[i];
	}

	displayArea.x = 0;
	displayArea.y = 0;
	displayArea.w = 0;
	displayArea.h = 0;
}

SortMeasurement *Graph::getData()
{
	SortMeasurement *d = new SortMeasurement[n];
	for (int i = 0; i < n; i++)
	{
		d[i] = data[i];
	}

	return d;
}

void Graph::setXpos(int x)
{
	displayArea.x = x;
}

void Graph::setYpos(int y)
{
	displayArea.y = y;
}

void Graph::setWidth(int w)
{
	displayArea.w = w;
	columnCount = displayArea.w / (unitW * unitScale);

	/* TODO: Write program to find largest inputSize */
	SortMeasurement sm = data[9];
	int maxValue = sm.inputSize;
	if (maxValue > 0) {
		deltaX = (maxValue / columnCount + (maxValue % columnCount > 0 ? 1 : 0)); // Rounding up
	}
	else {
		deltaX = 1; // Avoid division by zero; set a default minimum.
	}
}

void Graph::setHeight(int h)
{
	displayArea.h = h;
	rowCount = displayArea.h / (unitH * unitScale);

	/* TODO: Write program to find largest time */
	SortMeasurement sm = data[9];
	int maxValue = sm.time;
	if (maxValue > 0)
	{
		deltaY = (maxValue / rowCount + (maxValue % rowCount > 0 ? 1 : 0)); // Rounding up
	}
	else
	{
		deltaY = 1; // Avoid division by zero; set a default minimum.
	}
}

void Graph::setUnitScale(int s)
{
	unitScale = s;
}

void Graph::draw()
{

	/* Draw Graph Lines */

	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

	int x;
	for (int i = 1; i <= columnCount; i++)
	{
		x = displayArea.x + i * unitW * unitScale;
		SDL_RenderDrawLine(renderer, x, displayArea.y, x, displayArea.y + displayArea.h);
	}

	int y;
	for (int i = 0; i < rowCount; i++)
	{
		y = displayArea.y + i * unitH * unitScale;
		SDL_RenderDrawLine(renderer, displayArea.x, y, displayArea.x + displayArea.w, y);
	}

	/* Draw Data Points */
	SDL_Point *points = new SDL_Point[n];

	for (int i = 0; i < n; i++)
	{
		SDL_Point p = {data[i].inputSize * unitW * unitScale / deltaX + displayArea.x, -data[i].time * unitH * unitScale / deltaY + displayArea.y + displayArea.h};
		points[i] = p;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLines(renderer, points, n);

	/* Draw Graph Boundary */
	// SDL_RenderDrawRect(renderer, &displayArea);

	/* Draw X Axis */
	SDL_RenderDrawLine(renderer, displayArea.x, displayArea.y + displayArea.h, displayArea.x + displayArea.w, displayArea.y + displayArea.h);

	/* Draw Y Axis */
	SDL_RenderDrawLine(renderer, displayArea.x, displayArea.y + displayArea.h, displayArea.x, displayArea.y);
}