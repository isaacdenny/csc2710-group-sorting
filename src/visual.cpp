#include "visual.h"

int displayData(int data[], int n)
{
    const int COLUMN_COUNT = 20;
    const int ROW_COUNT = 40;
    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;
    const int UNIT_WIDTH = WINDOW_WIDTH / COLUMN_COUNT;
    const int UNIT_HEIGHT = WINDOW_HEIGHT / ROW_COUNT;

    SDL_Surface *windowSurface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect r;
    r.w = COLUMN_COUNT * UNIT_WIDTH / 2;
    r.h = ROW_COUNT * UNIT_HEIGHT / 3;
    r.x = WINDOW_WIDTH / 2 - r.w / 2;
    r.y = WINDOW_HEIGHT / 2 - r.h / 2;

    SDL_Point *points = new SDL_Point[n];

    for (int i = 0; i < n; i++)
    {
        SDL_Point p = { i * UNIT_WIDTH + r.x, -data[i] * UNIT_HEIGHT + r.y + r.h };
        points[i] = p;
    }


    // Main loop flag
    bool quit = false;
    SDL_Event e;

    // Main loop
    while (!quit)
    {
        SDL_Delay(10);
        SDL_PollEvent(&e);

        switch (e.type) {
        case SDL_QUIT:
            quit = true;
            break;
            // TODO input handling code goes here
        }

        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLines(renderer, points, n);
        SDL_RenderDrawRect(renderer, &r);

        // render drawings
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}