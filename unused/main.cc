#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <vector>

#include "geometry.h"
#include "model.h"
#include "tgaimage.h"

TGAColor const white = TGAColor(255, 255, 255, 255);
TGAColor const red = TGAColor(255, 0, 0, 255);
TGAColor const blue = TGAColor(159, 216, 223, 255);
int const height = 800;
int const width = 800;
std::array<std::array<float, height>, width> z_buffer;

Vec3f WorldToScreen(Vec3f v) {
  return Vec3f((v.x + 1.0) * width / 2, (v.y + 1.0) * height / 2, v.z);
}

Vec3f BaryCentric(Vec2f const &A, Vec2f const &B, Vec2f const &C,
                  Vec2f const &P) {
  Vec3f s[2];
  s[0].x = B.x - A.x;
  s[0].y = C.x - A.x;
  s[0].z = A.x - P.x;

  s[1].x = B.y - A.y;
  s[1].y = C.y - A.y;
  s[1].z = A.y - P.y;

  Vec3f u = s[0] ^ s[1];
  if (std::abs(u.z) > 1e-2) {
    return Vec3f(1.f - (u.x + u.y) / u.z, u.y / u.z, u.x / u.z);
  };
  return Vec3f(-1, 1, 1);  // in this case generate negative coordinates, it
                           // will be thrown away by the rasterizator
}
//开启z-buffer深度测试
void triangle(std::vector<Vec3f> points, TGAImage &image, TGAColor color) {
  std::for_each(points.begin(), points.end(),
                [](Vec3f &i) { i = WorldToScreen(i); });
  float max_x = std::max({points[0].x, points[1].x, points[2].x});
  float min_x = std::min({points[0].x, points[1].x, points[2].x});
  float max_y = std::max({points[0].y, points[1].y, points[2].y});
  float min_y = std::min({points[0].y, points[1].y, points[2].y});

  for (float x = min_x; x <= max_x; x++) {
    for (float y = min_y; y < max_y; y++) {
      Vec2f point = Vec2f(x, y);

      Vec2f tri_line_0 = points[0].get2D() - points[1].get2D();
      Vec2f tri_line_1 = points[1].get2D() - points[2].get2D();
      Vec2f tri_line_2 = points[2].get2D() - points[0].get2D();
      Vec2f point_line_0 = points[0].get2D() - point;
      Vec2f point_line_1 = points[1].get2D() - point;
      Vec2f point_line_2 = points[2].get2D() - point;
      if (!(CrossProductSign(tri_line_0, point_line_0) ^
            CrossProductSign(tri_line_1, point_line_1)) &&
          !(CrossProductSign(tri_line_0, point_line_0) ^
            CrossProductSign(tri_line_2, point_line_2))) {
        Vec3f bary_cor = BaryCentric(points[0].get2D(), points[1].get2D(),
                                     points[2].get2D(), point);

        float z_value = bary_cor * Vec3f(points[0].z, points[1].z, points[2].z);
        if (z_value > z_buffer[x][y]) {
          z_buffer[x][y] = z_value;
          // image.set(x, y, color);
          image.set(x, y, color);
        }
      }
    }
  }
}
int main() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      z_buffer[i][j] = std::numeric_limits<float>::min();
    }
  }
  TGAImage image(width, height, TGAImage::RGB);
  Model *model = new Model("../obj/african_head.obj");
  for (int i = 0; i < model->nfaces(); i++) {
    std::vector<int> face = model->face(i);
    std::vector<Vec3f> points;
    for (int j = 0; j < 3; j++) {
      points.push_back(model->vert(face[j]));
    }
    int c = rand() % 255;
    triangle(points, image, TGAColor(c, c, c, 255));
  }

  image.flip_vertically();
  image.write_tga_file("output.tga");
  return 0;
}

// draw line with model
// for (int i = 0; i < model->nfaces(); i++) {
//   std::vector<int> face = model->face(i);
//   for (int j = 0; j < 3; j++) {
//     Vec3f v0 = model->vert(face[j]);
//     Vec3f v1 = model->vert(face[(j + 1) % 3]);
//     int x0 = (v0.x + 1.) * width / 2.;
//     int y0 = (v0.y + 1.) * height / 2.;
//     int x1 = (v1.x + 1.) * width / 2.;
//     int y1 = (v1.y + 1.) * height / 2.;
//     line(x0, y0, x1, y1, image, blue);
//   }
// }