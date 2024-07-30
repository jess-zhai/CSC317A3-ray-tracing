#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // https://en.wikipedia.org/wiki/Blinn–Phong_reflection_model
  Eigen::Vector3d p = ray.origin + t * ray.direction;
  Eigen::Vector3d rgb(0, 0, 0);
  rgb += objects[hit_id]->material->ka * 0.1;
  for (int i = 0; i < lights.size(); i++){
    double max_t;
    Ray light_ray;
    light_ray.origin = p;
    lights[i]->direction(light_ray.origin, light_ray.direction, max_t);

    int hit_id2;
    double t2;
    Eigen::Vector3d n2;
    if (!first_hit(light_ray, 1.0e-5, objects, hit_id2, t2, n2) || t2 >= max_t){
      double l = n.dot(light_ray.direction);
      if (l < 0){
        l = 0;
      }
      Eigen::Vector3d v = (-ray.direction).normalized();
      Eigen::Vector3d h = (light_ray.direction + v).normalized();
      double h_dot_n = n.dot(h);
      if (h_dot_n < 0){
        h_dot_n = 0;
      }
      rgb += (objects[hit_id]->material->kd.array() * lights[i]->I.array()).matrix() * l;
      rgb += (objects[hit_id]->material->ks.array() * lights[i]->I.array()).matrix() * std::pow(h_dot_n, objects[hit_id]->material->phong_exponent);
    }
  }
  return rgb;

  ////////////////////////////////////////////////////////////////////////////
}
