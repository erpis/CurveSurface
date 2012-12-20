#ifndef OPENGL_IMPL_H
#define OPENGL_IMPL_H

#include <functional>

#include "opengl_macro.h"

using namespace std;

class opengl_impl {
	function<void(double, double, double, int)> draw_behavior;
	static const int N = 100;

private:
	opengl_impl& operator =(const opengl_impl &rhs);
	opengl_impl(const opengl_impl &rhs);

public:
	opengl_impl(double x = 50.0, double y = 50.0, double radius = 50.0);
	void draw();
	void resize(int w, int h);
	void keyboard_handler(unsigned char key, int x, int y);

private:
	double center_x;
	double center_y;
	double R;
};

#endif