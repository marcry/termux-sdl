
// For test SDL_AndroidLogPrint

#include "SDL2/SDL.h"

#define WIDTH 640
#define HEIGHT 480

// define log tag
#define TAG "SDL2"

SDL_Window* window = NULL;
SDL_Renderer* render = NULL;
SDL_Texture* texture = NULL;

bool sdl_init() {
    window = SDL_CreateWindow("SDL Hello World",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
        // show error log in java program
        SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", "creat window error");
        return false;
    }
    render = SDL_CreateRenderer(window, -1, 0);
    if (render == NULL) {
        SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", "creat render error");
        return false;
    }
    return true;
}

bool load_image() {
    SDL_Surface* surface = NULL;
    hello = SDL_LoadBMP("hello.bmp");
    if (surface == NULL) {
        SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", "load bmp error");
        return false;
    }
    tex = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
    if (texture == NULL) {
        SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", "creat surface texture error");
        return false;
    }
    return true;
}

void display_image() {
    SDL_RenderCopy(render, texture, NULL, NULL);
    SDL_RenderPresent(render);
    SDL_Delay(3000);
}

void quit() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}

int main(int argc, char *args[]) {
    // show log info to java program
    SDL_AndroidLogPrint(LOG_INFO, TAG, "%s\n", "Hello World!");

    if (sdl_init()) {
        if(load_image()) display_image();
        quit();
    }
    return 0;
}