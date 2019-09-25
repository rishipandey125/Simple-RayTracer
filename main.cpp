/**
* Sphere raytracer project developed by Rishi Pandey.
* main.cpp
**/

#include "RayTracer.cpp"
using namespace std;

int main() {
  vector<int> dimensions{1000,1500,-1500}; //formated as {height,width,depth}
  //colors of spheres
  vector <int> purple{178,102,255};
  vector <int> pink{255,128,255};
  vector <int> teal{0,204,153};
  vector <int> orange {255,119,51};
  vector <int> red {255,51,51};
  vector <int> blue{51,133,255};
  vector <int> yellow {255,255,102};
  vector <int> green {0,230,77};
  //center points of spheres (cartesian coordiantes)
  Point p1(750,0,-200);
  Point p2(300,0,-900);
  Point p3(1200,0,-900);
  Point p4(1000,100,-400);
  Point p5(500,100,-400);



  //cartesian coordinates of light sources
  Point l(750,800,400);
  //sphere objects
  Sphere first(150,p1,purple);
  Sphere s_c3(200,p2,orange);
  Sphere last(200,p3,orange);
  Sphere s_p4(100,p4,teal);
  Sphere s_p5(100,p5,teal);

  //all sphere objects in the scene
  std::vector <Sphere> objects {first,s_c3,last,s_p4,s_p5};
  //all light points in the scene
  std::vector <Point> lights{l};
  render_image(dimensions, objects, lights);
  return 0;
}
