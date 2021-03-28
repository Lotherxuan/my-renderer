#ifndef LIB_SHADERS_INCLUDE_GOURAUND_SHADER_H
#define LIB_SHADERS_INCLUDE_GOURAUND_SHADER_H
#include "our_gl.h"

struct GouraudShader : public IShader {
  Vec3f varying_intensity;
  // written by vertex shader, read by fragment shader
  virtual Vec4f vertex(int iface, int nthvert);
  virtual bool fragment(Vec3f bar, TGAColor &color);
};

#endif