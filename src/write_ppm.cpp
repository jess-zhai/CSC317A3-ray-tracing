#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  std::ofstream ppmFile(filename, std::ios::out | std::ios::binary);
  if (!ppmFile.is_open()) {
    return false; 
  }
  if (num_channels == 1) {
    ppmFile << "P2\n";
  } else {
    ppmFile << "P3\n";
  }
  ppmFile << width << " " << height << "\n";
  ppmFile << "255\n";

  // Write pixel data
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      int pixelStart = (h * width + w) * num_channels;
      for (int channel = 0; channel < num_channels; ++channel) {
        ppmFile << static_cast<int>(data[pixelStart + channel]);
        if (channel < num_channels - 1) {
          ppmFile << " ";
        }
      }
      ppmFile << "\n";
    }
  }

  ppmFile.close();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
