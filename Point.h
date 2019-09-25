#ifndef POINT_H
#define POINT_H
class Point {
public:
  //cartesian constructor
  Point(double xCord, double yCord, double zCord);
  //default constructor
  Point();
  //get x coordinate
  double getX();
  //set x coordinate
  void setX(double xCord);
  //get y coordinate
  double getY();
  //set y coordinate
  void setY(double yCord);
  //get z coordinate
  double getZ();
  //set z coordinate
  void setZ(double zCord);
private:
  //x coordinate of point
  double x;
  //y coordinate of point
  double y;
  //z coordinate of point
  double z;
};
#endif
