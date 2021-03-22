#include <iostream>

#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor blud = TGAColor(159, 216, 223, 255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
  bool steep = std::abs(y1 - y0) > std::abs(x1 - x0);
  if (steep) {
    std::swap(x0, y0);
    std::swap(x1, y1);
  }
  if (x0 > x1) {
    std::swap(x0, x1);
    std::swap(y0, y1);
  }
  int dx = x1 - x0;
  int y_step = y1 > y0 ? 1 : 0;
  int dy = std::abs(y1 - y0);
  int error = 0;
  int y = y0;
  for (int x = x0; x <= x1; x++) {
    if (error >= dx) {
      y++;
      error = error - 2 * dx;
    }
    if (steep) {
      image.set(y, x, color);
    } else {
      image.set(x, y, color);
    }
    error += 2 * dy;
  }
}
int main() {
  TGAImage image(100, 100, TGAImage::RGB);
  line(80, 40, 74, 13, image, blud);
  image.flip_vertically();
  image.write_tga_file("output.tga");
  return 0;
}
