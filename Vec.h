#ifndef VEC_H
#define VEC_H
class Vec {
public:
  //Vector Constructor using Point tail and Point head.
  Vec(Point t, Point h);
  //Vector constructor using x,y,z length.
  Vec(double xl, double yl, double zl);
  //calculates magnitude of 3D vector
  double magnitude();
  //gets x value of 3D vector
  double getX();
  //gets y value of 3D vector
  double getY();
  //gets z value of 3D vector
  double getZ();
  //normalizes 3D vector
  void unit();

private:
  //x value of 3D vector
  double x;
  //y value of 3D vector
  double y;
  //z value of 3D vector
  double z;
};
#endif
