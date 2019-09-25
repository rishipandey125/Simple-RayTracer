#include "Vec.h"
#include <cmath>
/**
*3D Vector Class.
*/

/**
* Vector Constructor using Point tail and Point head.
* @param t, point of tail.
* @param h, point of head.
*/
Vec::Vec(Point t, Point h) {
  x = h.getX() - t.getX();
  y = h.getY() - t.getY();
  z = h.getZ() - t.getZ();
}

/**
* Vector constructor using x,y,z length.
* @param xl, length of x.
* @param yl, length of y.
* @param zl, length of z.
*/
Vec::Vec(double xl, double yl, double zl) {
  x = xl;
  y = yl;
  z = zl;
}

/**
* Calculates the Magnitude of a 3D Vector.
* @return magnitude of 3D Vector as a double datatype.
*/
double Vec::magnitude() {
  return sqrt((x*x) + (y*y) + (z*z));
}

/**
* Gets the x value of a 3D Vector.
* @return x, x value of 3D Vector.
*/
double Vec::getX() {
  return x;
}

/**
* Gets the y value of a 3D Vector.
* @return y, y value of 3D Vector.
*/
double Vec::getY() {
  return y;
}

/**
* Gets the z value of a 3D Vector.
* @return z, z value of 3D Vector.
*/
double Vec::getZ() {
  return z;
}

/**
* Normalizes 3D Vector.
*/
void Vec::unit() {
  double magnitude = sqrt((x*x) + (y*y) + (z*z));
  x = x/magnitude;
  y = y/magnitude;
  z = z/magnitude;
}
