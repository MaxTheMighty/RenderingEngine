#include "../include/parser.h"

WavefrontLine Parser::StrToWavefrontLine(std::string &line){
  int pos = line.find(' ');
  std::string line_type;
  if(pos == std::string::npos){
    std::cout << "Line isnt empty but has no spaces, returning invalid!" << std::endl;
    return invalid;
  }
  line_type = line.substr(0,pos);
  if(line_type == "v"){return WavefrontLine::vertex;}
  if(line_type == "f"){return WavefrontLine::face;}
  if(line_type == "vn"){return WavefrontLine::vertex_normal;}
  if(line_type == "vt"){return WavefrontLine::texture_coordinate;}
  if(line_type == "#"){return WavefrontLine::ignore;}
  if(line_type == "s"){return WavefrontLine::ignore;}
  if(line_type == "g"){return WavefrontLine::ignore;}
  return WavefrontLine::invalid;

}


Model Parser::ParseWavefront(std::string filepath){
    Model model_out;
    std::ifstream filestream(filepath);
    std::string line;
    std::string face_index;
    std::stringstream stream;
    std::stringstream substream;
    WavefrontLine line_type;
    Point3f vertex;
    Vector3i edge;
    std::vector<Point3f> vertices;
    int vertex_count = 0;
    int edge_count = 0;
    int line_index = -1;
    while(std::getline(filestream,line)){
      if(line.empty()){
        continue;
      }
      line_type = Parser::StrToWavefrontLine(line);

      switch (line_type) {
        line_index +=1;
        case WavefrontLine::vertex:
          vertex = Point3f();
          stream = std::stringstream(line.substr(2));
          vertex_count = 0;
          while(std::getline(stream, line, ' ')){
            if(vertex_count > 2){
             std::cout << "Vertex count above 2: " << vertex_count << std::endl;
            }
            vertex[vertex_count] = std::stof(line);
            vertex_count+=1;
          }
          vertices.push_back(vertex);
          continue;
        case WavefrontLine::face:
          edge = Vector3i();
          stream = std::stringstream(line.substr(2));
          edge_count = 0;
          while(std::getline(stream, line, ' ')){
            if (edge_count > 2) {
              std::cout << "Edge count above 2:" << edge_count << std::endl;
            }
            substream = std::stringstream(line);
            std::getline(substream, face_index, '/'); //only get the first number
            edge[edge_count] = stoi(face_index)-1;
            edge_count+=1;
          }
          model_out.triangles.emplace_back(vertices[edge.x],vertices[edge.y],vertices[edge.z]);
          continue;
        case WavefrontLine::texture_coordinate:
          continue;
        case WavefrontLine::vertex_normal:
          continue;
        case WavefrontLine::invalid:
          std::cout << "Got an invalid line while parsing wavefront" << std::endl;
          std::cout << "Line: " << line << std::endl;
          std::cout << "Line index: " << line_index << std::endl;
          break;
      }


    }
    std::cout << "Finished parsing!" << std::endl;
    return model_out;
  }