#ifndef GRAPH_H
#define GRAPH_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "sorts.h"
#include <string>
#include <cmath>

class Graph
{
public:
    Graph(SDL_Renderer *renderer, SortMeasurement data[], int n, char *title);
    ~Graph();
    int getXpos() { return displayArea.x; }
    int getYpos() { return displayArea.y; }
    int getWidth() { return displayArea.w; }
    int getHeight() { return displayArea.h; }
    SortMeasurement *getData();
    void setXpos(int x);
    void setYpos(int y);
    void setWidth(int w);
    void setHeight(int h);
    void setUnitScale(int s);
    void draw();

private:
    SDL_Renderer *renderer;
    SDL_Rect displayArea;
    int n;
    char *title;
    int maxDataX, maxDataY;
    int unitW, unitH, deltaX, deltaY, unitScale, columnCount, rowCount;
    SDL_Color textColor = {0, 0, 0, 255}, graphColor = {200, 200, 200, 255}, axisColor = {0, 0, 0, 255};
    TTF_Font *font;
    SortMeasurement *data;
    void drawLabel(const std::string &label, int x, int y, double xOffset, double yOffset);
    void updateDeltaX();
    void updateDeltaY();
};

#endif