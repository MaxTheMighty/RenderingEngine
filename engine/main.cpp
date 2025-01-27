//
// Created by Maxwell Kozlov on 1/25/25.
//

#include <iostream>
#include <SDL3/sdl.h>
#include "SDL3/SDL_events.h"
#include "include/canvas.h"
#include "include/parser.h"
//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;


int main() {

  

    Model model;
    model = Parser::ParseWavefront("obj/face.obj");

    Canvas canvas("Rendering engine",SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);
    SDL_Event event;
    int current_triangle = 0;
    while (true){
        while (SDL_PollEvent(&event) != false) {
            if (event.type == SDL_EVENT_QUIT) {
                return -1;
            }
        }


    if (current_triangle < model.triangles.size()) {
        canvas.RenderClearColor(0,0,0,255);
        canvas.SetColor(255,255,255,255);
        for(int i = 0; i < current_triangle; i++){
            canvas.DrawTriangle(model.triangles[i]);
        }
        SDL_Delay(5);
        canvas.RenderPresent();
    }
    current_triangle+=1;

    // canvas.RenderPresent();
}


}
