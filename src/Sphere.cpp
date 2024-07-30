#include "Sphere.h"
#include "Ray.h"

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double a = ray.direction.dot(ray.direction);
  double b = 2 * ray.direction.dot(ray.origin - center);
  double c = (ray.origin - center).dot(ray.origin - center) - std::pow(radius, 2);

  double discriminant = std::pow(b, 2) - 4*a*c;

  if (discriminant < 0){
    return false;
  } else if (discriminant == 0){
    double t_temp = (double) -1 * b / (2*a);
    if (t_temp >= min_t){
      t = t_temp;
    } else {
      return false;
    }
  } else {
    double t1 = (double) (-1 * b + std::sqrt(discriminant)) / (2*a);
    double t2 = (double) (-1 * b - std::sqrt(discriminant)) / (2*a);
    if(t1 < min_t){
      return false;
    } else if (t2 >= min_t){
      t = t2;
    } else {
      t = t1;
    }
  }
  n = (ray.origin + t * ray.direction - center) / radius;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

