#ifndef MATH_H_
#define MATH_H_


#define EPSILON 1e-6
#define isZero(v) (((v)>0? (v): -(v))<=1e-6)

#define toRadian(a) ((a)*3.1415926f/180.0f)
#define toDegree(a) ((a)*180.0f/3.1415926f)

#include <Poor3D/Math/Vec3f.h>
#include <Poor3D/Math/Mat4.h>
#include <Poor3D/Math/Mat3.h>
#include <Poor3D/Math/TransMat4.h>


#endif
