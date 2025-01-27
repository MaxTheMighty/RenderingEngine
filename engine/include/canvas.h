//
// Created by Maxwell Kozlov on 1/25/25.
//
#include <SDL3/sdl.h>
#include "triangle.h"

#ifndef CANVAS_H
#define CANVAS_H
struct Color{
  Uint8 r;
  Uint8 g;
  Uint8 b;
  Uint8 a;
};

class Canvas{
  public:
  SDL_Window* window;
  SDL_Renderer* renderer;
  int screen_width;
  int screen_height;
  SDL_WindowFlags window_flags;
  Color color;
  
  Canvas(const char* window_name, int screen_width, int screen_height, SDL_WindowFlags window_flags);
  void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  void DrawLine(float startX, float startY, float endX, float endY);
  void RenderClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  void RenderClear();
  void RenderPresent();
  void DrawPixel(float x, float y);
  void DrawPixel(float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
  void DrawTriangle(Triangle t);
};
#endif //CANVAS_H 
