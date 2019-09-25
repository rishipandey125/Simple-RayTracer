#ifndef SPHERE_H
#define SPHERE_H
class Sphere {
public:
  //sphere constructor
  Sphere(double rad, Point c, std::vector <int> color);
  //gets radius of sphere
  double getRadius();
  //gets center of sphere
  Point getCenter();
  //sets radius of sphere
  void setRadius(double rad);
  //gets r (rgb) value of sphere color
  int red();
  //gets g (rgb) value of sphere color
  int green();
  //gets b (rgb) value of sphere color
  int blue();
private:
  //radius of sphere
  double radius;
  //center of sphere
  Point center;
  //r (rgb) color of sphere
  int r;
  //g (rgb) color of sphere
  int g;
  //b (rgb) color of sphere
  int b;
};
#endif
