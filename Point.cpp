#include "Point.h"
/**
*Cartesian Point Class.
*/

/**
*Constructor (x,y,z) coordinates.
*@param xCord, cartesian x coordinate.
*@param yCord, cartesian y coordinate.
*@param zCord, cartesian z coordinate.
*/
Point::Point(double xCord, double yCord, double zCord) {
  x = xCord;
  y = yCord;
  z = zCord;
}

/**
*Default Constructor sets (x,y,z) coordinates to 0.
*/
Point::Point() {
  x = 0;
  y = 0;
  z = 0;
}

/**
* Gets the x coordinate of a point.
* @return x coordinate.
*/
double Point::getX() {
  return x;
}

/**
* Sets the x coordinate of a point.
* @param xCord, sets x coordinate.
*/
void Point::setX(double xCord) {
  x = xCord;
}

/**
* Gets the y coordinate of a point.
* @return y coordinate.
*/
double Point::getY() {
  return y;
}

/**
* Sets the y coordinate of a point.
* @param yCord, sets y coordinate.
*/
void Point::setY(double yCord) {
  y = yCord;
}

/**
* Gets the z coordinate of a point.
* @return z coordinate.
*/
double Point::getZ() {
  return z;
}

/**
* Sets the z coordinate of a point.
* @param zCord, sets z coordinate.
*/
void Point::setZ(double zCord) {
  z = zCord;
}
