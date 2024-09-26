#ifndef GRAPH_H
#define GRAPH_H

#include <SDL.h>
#include <iostream>
#include "sorts.h"

class Graph {
public:
	Graph(SDL_Renderer* renderer, SortMeasurement data[], int n);
	int getXpos() { return displayArea.x; }
	int getYpos() { return displayArea.y; }
	int getWidth() { return displayArea.w; }
	int getHeight() { return displayArea.h; }
	SortMeasurement* getData();
	void setXpos(int x);
	void setYpos(int y);
	void setWidth(int w);
	void setHeight(int h);
	void setUnitScale(int s);
	void draw();

private:
	SDL_Renderer* renderer;
	SDL_Rect displayArea;
	int n;
	int unitW, unitH, deltaX, deltaY, unitScale, columnCount, rowCount;
	SortMeasurement *data;
};

#endif