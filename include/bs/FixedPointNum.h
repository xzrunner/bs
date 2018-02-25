#pragma once

#include <math.h>

namespace bs
{

// to int

inline
int time2int(float time) {
	return static_cast<int>(floor(time * 1000 + 0.5f));
}

inline
int radian2int(float r) {
	return static_cast<int>(floor(r * 180.0f / 3.1415926f + 0.5f));
}

inline
int float2int(float f) {
	return static_cast<int>(floor(f + 0.5f));
}

inline int float2int(float f, int precision) {
	return float2int(f * precision);
}

inline
int bool2int(bool b) {
	return b ? 1 : 0;
}

// from int

inline
float int2time(int time) {
	return time * 0.001f;
}

inline
float int2radian(int deg) {
	return deg * 3.1415926f / 180.0f;
}

inline
float int2float(int i, int precision) {
	return (float)i / precision;
}

inline
bool int2bool(int i) {
	return i == 1 ? true : false;
}

}