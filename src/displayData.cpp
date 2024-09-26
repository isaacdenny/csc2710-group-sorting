#include "displayData.h"

int displayData(SortMeasurement data[], int n)
{
    const int COLUMN_COUNT = 20;
    const int ROW_COUNT = 40;
    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;
    const int UNIT_WIDTH = WINDOW_WIDTH / COLUMN_COUNT;
    const int UNIT_HEIGHT = WINDOW_HEIGHT / ROW_COUNT;
    const int H_PADDING = UNIT_WIDTH * 2;
    const int V_PADDING = UNIT_HEIGHT * 2;

    SDL_Surface *windowSurface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    if (TTF_Init() == -1)
    {
        std::cerr << "TTF Initialization Error: " << TTF_GetError() << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);

    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Graph g(renderer, data, n, "Sorted: Time vs Input Size");
    g.setWidth(WINDOW_WIDTH - H_PADDING * 2);
    g.setHeight(WINDOW_HEIGHT / 3);
    g.setXpos(H_PADDING);
    g.setYpos(V_PADDING);

    // Main loop flag
    bool quit = false;
    SDL_Event e;

    // Main loop
    while (!quit)
    {
        SDL_Delay(10);
        SDL_PollEvent(&e);

        switch (e.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_WINDOWEVENT:
            if (e.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                g.setWidth((e.window.data1 - H_PADDING * 2) / 3);
                g.setHeight(e.window.data2 / 3);
            }
            break;
            // TODO input handling code goes here
        }

        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
        SDL_RenderClear(renderer);

        // draw graph here
        g.draw();
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();

    return 0;
}