#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>
#include <iostream>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  //Replace with your code here:
  Eigen::Vector3d pt1 = std::get<0>(corners);
  Eigen::Vector3d pt2 = std::get<1>(corners);
  Eigen::Vector3d pt3 = std::get<2>(corners);
  Eigen::Vector3d edge1 = pt2 - pt1;
  Eigen::Vector3d edge2 = pt3 - pt1;
  Eigen::Vector3d h = ray.direction.cross(edge2);
  double a = edge1.dot(h);

  // if (a > -min_t && a < min_t){
  //   return false;
  // }
  Eigen::Vector3d normal = edge1.cross(edge2);
  if (normal.dot(ray.direction) == 0) {
    return false;
  }

  double f = 1.0/a;
  Eigen::Vector3d s = ray.origin - pt1;
  double u = f * s.dot(h);

  if (u < 0.0 || u > 1.0){
    return false;
  }
  Eigen::Vector3d q = s.cross(edge1);
  double v = f * ray.direction.dot(q);
  if (v < 0.0 || u + v > 1.0){
    return false;
  }
  
  double t_temp = f * edge2.dot(q);
  if (t_temp > min_t){
    t = t_temp;
    n = normal.normalized();
    return true;
  } else {
    return false;
  }

  ////////////////////////////////////////////////////////////////////////////
}


