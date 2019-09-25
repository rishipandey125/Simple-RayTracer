#include "Sphere.h"
#include <vector>
/**
* Sphere Object Class.
*/

/**
* Sphere Object Constructor.
* @param rad, radius of Sphere.
* @param c, cartesian center point of Sphere.
* @param color, RGB <vector> of Sphere.
*/
Sphere::Sphere(double rad, Point c, std::vector <int> color) {
  radius = rad;
  center = c;
  r = color[0];
  g = color[1];
  b = color[2];
}

/**
* Gets radius of Sphere.
* @return radius.
*/
double Sphere::getRadius() {
  return radius;
}

/**
* Gets center of Sphere.
* @return center.
*/
Point Sphere::getCenter() {
  return center;
}

/**
* Sets radius of Sphere.
* @param rad, value of new radius.
*/
void Sphere::setRadius(double rad) {
  radius = rad;
}

/**
* Gets r in the rgb value of the Sphere.
* @return r.
*/
int Sphere::red() {
  return r;
}

/**
* Gets g in the rgb value of the Sphere.
* @return g.
*/
int Sphere::green() {
  return g;
}

/**
* Getsb b in the rgb value of the Sphere.
* @return b.
*/
int Sphere::blue() {
  return b;
}
