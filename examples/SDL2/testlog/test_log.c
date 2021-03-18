
// For test SDL_AndroidLogPrint

#include "SDL2/SDL.h"

#define WIDTH 480
#define HEIGHT 640

// define log tag
#define TAG "SDL2 Log"

int main(int argc, char *args[]) {
    
    SDL_Window* win = SDL_CreateWindow("SDL Hello World",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (win == NULL) {
        // print log to java program
        SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", SDL_GetError());
        SDL_Quit();
    }
    
    SDL_Surface *surface = SDL_GetWindowSurface(win);
    
    // fill surface with red color
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0x00, 0x00));

    // update surface
    SDL_UpdateWindowSurface(win);
    
    // print log to java program
    for(int i=0; i<100;++i) {
        SDL_AndroidLogPrint(LOG_INFO, TAG, "%s\n", "Hello World From SDL2.");
        SDL_Delay(50);
    }
    
    // sleep 1000s
    SDL_Delay(1000000);
    
    //SDL_FreeSurface(surface);
    SDL_DestroyWindow(win);
    SDL_Quit();
    
    return 0;
}