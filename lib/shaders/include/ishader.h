#ifndef LIB_SHADERS_INCLUDE_ISHADER_H
#define LIB_SHADERS_INCLUDE_ISHADER_H
#include "geometry.h"
#include "tgaimage.h"
struct IShader {
  virtual ~IShader();
  virtual Vec4f vertex(int iface, int nthvert) = 0;
  virtual bool fragment(Vec3f bar, TGAColor &color) = 0;
};
#endif