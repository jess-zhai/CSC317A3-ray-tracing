#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double min = std::numeric_limits<double>::infinity();
  bool hit = false;
  double t2;
  Eigen::Vector3d n2;
  for (int i=0; i< objects.size(); i++){
    bool new_hit = objects[i]->intersect(ray, min_t, t2, n2);

    if (new_hit){
      hit = true;
      if(t2 < min){
        min = t2;
        hit_id = i;
        t = t2;
        n = n2;
      }
    }
  }
  return hit;
  ////////////////////////////////////////////////////////////////////////////
}
