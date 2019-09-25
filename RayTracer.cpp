#include <iostream>
#include "Point.cpp"
#include "Vec.cpp"
#include "Sphere.cpp"
#include <vector>
#include <cmath>
using namespace std;

/**
*Function to retrieve the x and y bounds of a Sphere object.
*@param s, Sphere object.
*@param x, boolean variable indication xbounds of ybounds.
*@return bounds, returns the x or y bounds in a <vector> formatted as [lower,upper].
*/
std::vector<int> getBounds(Sphere &s, bool x) {
  int center;
  if (!x) {
    //y bounds
    center = s.getCenter().getY();
  } else {
    //x bounds
    center = s.getCenter().getX();
  }
  double r = s.getRadius();
  std::vector <int> bounds{int(center-r),int(center+r)};
  return bounds;
}

/**
*Function to check if an xy coordinate is inside the circle's radius.
*@param s, Sphere object.
*@param x, x coordinate.
*@param y, y coordiante.
*@return (true/false), returns true if the coordinates are within the radius, false otherwise.
*/
bool inRadius(Sphere &s, int x, int y) {
  double r = s.getRadius();
  int xC = s.getCenter().getX();
  int yC = s.getCenter().getY();
  double mag =  sqrt(((xC-x)*(xC-x) + ((yC-y)*(yC-y))));
  if (mag <= r) {return true;}
  return false;
}

/**
*Dots two Vec objects.
*@param a, The first Vec object.
*@param b, The second Vec object.
*@return value of the dot product as a double datatype.
*/
double dot(Vec a, Vec b) {
  return (a.getX()*b.getX()) + (a.getY()*b.getY()) + (a.getZ()*b.getZ());
}

/**
*Checks to see if a coordinate is part of a shadow.
*@param lights, <vector> of lights in the scene.
*@param pixel, given pixel to check.
*@param s, <vector> of Spheres in the scene.
*@param index, index of a specific sphere so we don't incorrectly calculate shadows.
*@return true if the pixel is part of a shadow, false otherwise.
*/
bool shadow(vector<Point> &lights, Point &pixel, vector<Sphere> &s, int index) {
  for (int j = 0; j < lights.size(); j++) {
    Vec x(pixel,lights[j]);
    double a = dot(x,x);
    for (int i = 0; i < s.size(); i++) {
      if (index != -1) {
        if (i == index or (s[index].getCenter().getZ() > s[i].getCenter().getZ())) {continue;}
      }
      int r = s[i].getRadius();
      Vec y(pixel,s[i].getCenter());
      double b = 2*dot(x,y);
      double c = dot(y,y)-(r*r);
      double discriminant = (b*b)-(4*a*c);
      if (discriminant >= 0) {
        return true;
      }
    }
  }
  return false;
}

/**
*Adds two Vec objects.
*@param a, The first Vec object.
*@param b, The second Vec object.
*@return a new Vec object (a + b).
*/
Vec vec_addition(Vec &a, Vec &b) {
  Vec v(a.getX()+b.getX(),a.getY()+b.getY(),a.getZ()+b.getZ());
  return v;
}

/**
*Clamps RGB values to remain between 0 and 255.
*@param val, RGB value.
*@return clamped value.
*/
int clamp255(int val) {
  if (val > 255) {
    val = 255;
  } else if (val < 0) {
    val = 0;
  }
  return val;
}

/**
*Calculates the Phong Shading value based on lights in the scene.
*@param normal, normal vector.
*@param view, view vector.
*@param ligth, light vector.
*@return phong shading value.
*/
double phong_shading(Vec &normal, Vec &view, Vec &light) {
  Vec h = vec_addition(light,view);
  h.unit();
  double diffuse = dot(normal,light);
  //ks = .2 and n = 200
  double specular = 0.2*pow(dot(normal,h),200);
  if (diffuse < 0) {diffuse=0;}
  if (specular < 0) {specular=0;}
  return diffuse + specular;
}

/**
*Renders final image of the scene as a .ppm file.
*@param dimensions, height, width and depth of the image.
*@param objects, <vector> of Spheres in the scene.
*@param lights, <vector> of lights in the scene.
*prints rgb values of the scene.
*/
void render_image(vector <int> &dimensions, vector <Sphere> &objects, vector <Point> &lights) {
  int height = dimensions[0]; int width = dimensions[1]; int depth = dimensions[2]; int ground = .75*height;
  double shadow_val = 0.15;
  //rgb of the sky and the ground (gray)
  vector <int> sky{128,212,255}; int gray = 211;
  Point camera(dimensions[1]/2,-1*dimensions[0],0);
  std::vector<vector<vector<int> > > image(height, vector<vector<int> >(width, vector<int>(4)));
  for (int i = 0; i < objects.size(); i++) {
    double zscale = 1-(objects[i].getCenter().getZ()/depth);
    if (zscale < 0) {zscale*=-1;}
    //scaling an object based on its depth
    objects[i].setRadius(objects[i].getRadius()*zscale);
    vector <int> xbounds = getBounds(objects[i],true);
    vector <int> ybounds = getBounds(objects[i],false);
    for (int y = ybounds[0]; y < ybounds[1]; y++) {
      for (int x = xbounds[0]; x < xbounds[1]; x++) {
        if (inRadius(objects[i],x,y)) {
          //cartesian z value of x,y coordinates
          int z = objects[i].getCenter().getZ() - sqrt(pow(objects[i].getRadius(),2)-pow((y-objects[i].getCenter().getY()),2));
          //current cartesian coordinates
          Point curr(x,y,z);
          Vec normal(objects[i].getCenter(),curr); Vec view(camera,curr);
          view.unit(); normal.unit();
          double phong = 0;
          if (shadow(lights,curr,objects,i)) {
            phong = shadow_val;
          } else {
            for (int j = 0; j < lights.size(); j++) {
              //temp_light used for accurate phong calculations within cartesian coordinate system
              Point temp_light(width-lights[j].getX(),height-lights[j].getY(),lights[j].getZ());
              Vec light(temp_light,curr); light.unit();
              phong += phong_shading(normal,view,light);
            }
          }
          int r = clamp255((int) (objects[i].red() * phong));
          int g = clamp255((int) (objects[i].green() * phong));
          int b = clamp255((int) (objects[i].blue() * phong));
          //pixel y value calculated from the cartesian y,z values
          int yp = (int) (((zscale*ground))-y+objects[i].getRadius());
          if (image[yp][x][3] != 1) {
            image[yp][x][0] = r; image[yp][x][1] = g; image[yp][x][2] = b; image[yp][x][3] = 1;
          }
        }
      }
    }
  }
  //spheres have been shaded, next the background!
  std::cout << "P3\n" << width << " " << height << "\n255\n";
  for (int y = 0; y < height; y++) {
    if (y > height - ground) {
      //shading the ground
      double z = (height-y) * (depth/ground);
      for (int x = 0; x < width; x++) {
        if (image[y][x][3] != 1) {
          Point curr(x,0,z);
          //shadows on the ground
          if (shadow(lights,curr,objects,-1)) {
            image[y][x][0] = gray*shadow_val; image[y][x][1] = gray*shadow_val; image[y][x][2] = gray*shadow_val; image[y][x][3] = 1;
          } else {
            image[y][x][0] = gray; image[y][x][1] = gray; image[y][x][2] = gray; image[y][x][3] = 1;
          }
        }
        std::cout << image[y][x][0] << " " << image[y][x][1] << " " << image[y][x][2] << "\n";
      }
    } else {
      //shading the sky
      for (int x = 0; x < width; x++) {
        if (image[y][x][3] != 1) {
          image[y][x][0] = sky[0]; image[y][x][1] = sky[1]; image[y][x][2] = sky[2]; image[y][x][3] = 1;
        }
        std::cout << image[y][x][0] << " " << image[y][x][1] << " " << image[y][x][2] << "\n";
      }
    }
  }
}
