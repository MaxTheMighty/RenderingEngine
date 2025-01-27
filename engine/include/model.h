#include <iostream>
#include "tuple3.h"
#include "point3.h"
#include "vector3.h"
#include <vector>


// store the vertices
  // a vertex is a three dimensional point in space
  // we can ignore the z dimension since we are just drawing lines
  // later we can do the perspective split 

// and the edges
  // these are triplets of vertices that form a triangle
  // these can just be tuple3i

class Model{
public:
  std::vector<Point3f> vertices;
  std::vector<Vector3i> edges;
  Model();
};
