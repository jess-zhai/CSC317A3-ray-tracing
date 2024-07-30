#include "Plane.h"
#include "Ray.h"
#include <iostream>
bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
   double dn = ray.direction.dot(normal);
  if (dn == 0){
    return false;
  }
  double t_temp = (point.dot(normal) - ray.origin.dot(normal))/ dn;

  if (t_temp < min_t){
    return false;
  } 
  t = t_temp;
  n = normal.normalized();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

