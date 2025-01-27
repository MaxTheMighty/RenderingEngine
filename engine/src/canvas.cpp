#include "../include/canvas.h"
#include "SDL3/SDL_render.h"

Canvas::Canvas(const char* window_name, int screen_width, int screen_height, SDL_WindowFlags window_flags){
  
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return;
    }
    this->screen_height = screen_height;
    this->screen_width = screen_width;
    this->window_flags = window_flags;
    this->window = SDL_CreateWindow("SDL Tutorial", screen_width,screen_height,window_flags);
    if(window == NULL){
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError()); 
      return;
    }

    this->renderer = SDL_CreateRenderer(window, NULL);
    if (this->renderer == NULL){
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());   
      return;
    }
}


void Canvas::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  if(this->color.r == r && this->color.g == g && this->color.b == b && this->color.a == a){
    return;
  }
  this->color = Color{r,g,b,a};
  SDL_SetRenderDrawColor(this->renderer,r,g,b,a);
}

void Canvas::DrawLine(float startX, float startY, float endX, float endY){
  SDL_RenderLine(this->renderer, startX, startY, endX, endY);
}

void Canvas::RenderClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  this->SetColor(r,g,b,a);
  SDL_RenderClear(this->renderer);

}

void Canvas::RenderClear(){
  SDL_RenderClear(this->renderer);
}

void Canvas::RenderPresent(){
  SDL_RenderPresent(this->renderer);
}

void Canvas::DrawPixel(float x, float y){
  SDL_RenderPoint(this->renderer,x,y);

}

void Canvas::DrawTriangle(Triangle t) {

  // normalize
  for (int i = 0; i < t.vertices.size(); i++) {
    t.vertices[i] = t.vertices[i] + 1;
    t.vertices[i] /= 2;
    t.vertices[i].x *= screen_width;
    t.vertices[i].y *= screen_height;
    t.vertices[i].y = screen_height- t.vertices[i].y;
  }


  Point3f edge_a = t.vertices[0];
  Point3f edge_b = t.vertices[1];
  Point3f edge_c = t.vertices[2];


  DrawLine(edge_a.x,edge_a.y,edge_b.x,edge_b.y);
  DrawLine(edge_b.x,edge_b.y,edge_c.x,edge_c.y);
  DrawLine(edge_a.x,edge_a.y,edge_c.x,edge_c.y);
}

void Canvas::DrawPixel(float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  this->SetColor(r,g,b,a);
  this->DrawPixel(x,y);
}
