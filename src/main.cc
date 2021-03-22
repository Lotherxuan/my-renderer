#include <algorithm>
#include <iostream>

#include "geometry.h"
#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor blue = TGAColor(159, 216, 223, 255);

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
void triangle(Vec2i *points, TGAImage &image, TGAColor color) {
  int max_x = std::max({points[0].u, points[1].u, points[2].u});
  int min_x = std::min({points[0].u, points[1].u, points[2].u});
  int max_y = std::max({points[0].v, points[1].v, points[2].v});
  int min_y = std::min({points[0].v, points[1].v, points[2].v});
  for (int x = min_x; x <= max_x; x++) {
    for (int y = min_y; y < max_y; y++) {
      Vec2i point = Vec2i(x, y);
      Vec2i tri_line_0 = points[0] - points[1];
      Vec2i tri_line_1 = points[1] - points[2];
      Vec2i tri_line_2 = points[2] - points[0];
      Vec2i point_line_0 = points[0] - point;
      Vec2i point_line_1 = points[1] - point;
      Vec2i point_line_2 = points[2] - point;
      if (!(CrossProductSign(tri_line_0, point_line_0) ^
            CrossProductSign(tri_line_1, point_line_1)) &&
          !(CrossProductSign(tri_line_0, point_line_0) ^
            CrossProductSign(tri_line_2, point_line_2))) {
        image.set(x, y, color);
      }
    }
  }
}
int main() {
  TGAImage image(200, 200, TGAImage::RGB);
  Vec2i pts[3] = {Vec2i(10, 10), Vec2i(100, 30), Vec2i(190, 160)};
  triangle(pts, image, blue);

  image.flip_vertically();
  image.write_tga_file("output.tga");
  return 0;
}
