#include <iostream>
#include "model.h"
#include <fstream>
#include <sstream>
#include "point3.h"
#include "vector3.h"

enum WavefrontLine{
  vertex,
  face,
  vertex_normal,
  texture_coordinate,
  ignore,
  invalid
};


class Parser{
public:
  static WavefrontLine StrToWavefrontLine(std::string &line);
  static Model ParseWavefront(std::string filepath);
};

