#include "gouraud_shader.h"

#include <algorithm>

#include "geometry.h"
#include "model.h"

extern Model *model;
Vec4f GouraudShader::vertex(int iface, int nthvert) {
  Vec3f light_dir(1, 1, 1);
  Vec4f gl_Vertex =
      embed<4>(model->vert(iface, nthvert));  // read the vertex from .obj file
  gl_Vertex = Viewport * Projection * ModelView *
              gl_Vertex;  // transform it to screen coordinates
  varying_intensity[nthvert] =
      std::max(0.f, model->normal(iface, nthvert) *
                        light_dir);  // get diffuse lighting intensity
  return gl_Vertex;
}

bool GouraudShader::fragment(Vec3f bar, TGAColor &color) {
  float intensity =
      varying_intensity * bar;  // interpolate intensity for the current pixel
  color = TGAColor(255, 255, 255) * intensity;  // well duh
  return false;  // no, we do not discard this pixel
}