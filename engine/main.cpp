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
    while (true){
        while (SDL_PollEvent(&event) != false) {
            if (event.type == SDL_EVENT_QUIT) {
                return -1;
            }
        }
    canvas.RenderClearColor(0,0,0,255);
    canvas.SetColor(255,255,255,255);
    for(int i = 0; i < model.edges.size(); i++){
        Vector3i vertex_index = model.edges[i];
        Point3f edge_a = model.vertices[vertex_index.x-1];
        Point3f edge_b = model.vertices[vertex_index.y-1];
        Point3f edge_c = model.vertices[vertex_index.z-1];

      // normalize
        edge_a = edge_a + 1;
        edge_a /= 2;
        edge_a.x *= SCREEN_WIDTH;
        edge_a.y *= SCREEN_HEIGHT;
        edge_a.y = SCREEN_HEIGHT - edge_a.y;

        edge_b = edge_b + 1;
        edge_b /= 2;
        edge_b.x *= SCREEN_WIDTH;
        edge_b.y *= SCREEN_HEIGHT;
        edge_b.y = SCREEN_HEIGHT - edge_b.y;

        edge_c = edge_c + 1;
        edge_c /= 2;
        edge_c.x *= SCREEN_WIDTH;
        edge_c.y *= SCREEN_HEIGHT;
        edge_c.y = SCREEN_HEIGHT - edge_c.y;


        canvas.DrawLine(edge_a.x,edge_a.y,edge_b.x,edge_b.y);
        canvas.DrawLine(edge_b.x,edge_b.y,edge_c.x,edge_c.y);
        canvas.DrawLine(edge_a.x,edge_a.y,edge_c.x,edge_c.y);
    }

    canvas.RenderPresent();
}


}
