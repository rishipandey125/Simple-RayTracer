/**
* Sphere raytracer project developed by Rishi Pandey.
* main.cpp
**/

#include "RayTracer.cpp"
using namespace std;

//features: multiple spheres, height&&depth, shadows, casted shadows
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
  Point front1(600,0,-500);
  Point front2(900,0,-500);
  Point left(400,100,-700);
  Point center(750,100,-700);
  Point right(1100,100,-700);
  Point left2(600,0,-900);
  Point right2(900,0,-900);
  Point p2(300,0,-900);
  Point p3(1200,0,-900);
  Point p4(1000,100,-400);
  Point p5(500,100,-400);



  //cartesian coordinates of light sources
  Point l(750,800,400);
  //sphere objects
  Sphere first(150,p1,purple);
  Sphere s_f1(150,front1,blue);
  Sphere s_f2(150,front2,blue);
  Sphere s_l(100,left,yellow);
  Sphere s_c(200,center,green);
  Sphere s_r(100,right,yellow);
  Sphere s_l2(200,left2,red);
  Sphere s_r2(200,right2,red);
  Sphere s_c3(200,p2,orange);
  Sphere last(200,p3,orange);
  Sphere s_p4(100,p4,teal);
  Sphere s_p5(100,p5,teal);

  //all sphere objects in the scene
  std::vector <Sphere> objects {first,s_p4,s_p5,s_f1,s_f2,s_l,s_c,s_r,s_c3,s_l2,s_r2,last};
  //all light points in the scene
  std::vector <Point> lights{l};
  render_image(dimensions, objects, lights);
  return 0;
}
