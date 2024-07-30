#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  double u =  ((double) -1* camera.width / 2) + (camera.width / width)*(j+0.5);
  double v = ((double) camera.height / 2) - (camera.height / height)*(i+0.5);

  Eigen::Vector3d direction = -1 * camera.d * camera.w + u * camera.u + v * camera.v;
  ray.origin = camera.e;
  ray.direction = direction.normalized();
  ////////////////////////////////////////////////////////////////////////////
}
