#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <GL/glut.h>
#include <cmath>
#include "opengl_macro.h"

#define PI 3.14159265

using namespace std;

namespace render_engine {

void draw_astroid(double x, double y, double R, int N) {
	gl_begin(GL_LINE_LOOP);
	float t;
	for (int i = 0; i < N; ++i) {
		t = (2*PI*i)/N;
		gl_vertex_3f(x + R*cos(t)*cos(t)*cos(t), y + R*sin(t)*sin(t)*sin(t), 0.0);
	}
	gl_end();
}

void draw_circle(double x, double y, double R, int N) {
	gl_begin(GL_LINE_LOOP);
	float t = 0;
	for (int i = 0; i < N; ++i) {
		gl_vertex_3f(x + R*cos(t), y + R*sin(t), 0.0);
		t += (2*PI)/N;
	}
	gl_end();
}

void draw_leminiscate_of_bernoulli(double x, double y, double R, int N) {
	float t = -PI;
	gl_begin(GL_LINE_LOOP);
	for (int i = 0; i < N; ++i) {
		gl_vertex_3f(x + R*cos(t)/(1 + sin(t)*sin(t)), y + R*cos(t)*sin(t)/(1 + sin(t)*sin(t)), 0.0f);
		t += (2*PI)/N;
	}
	gl_end();
}

void draw_witch_of_agnesi(double x, double y, double R, int N) {
	float t = -PI/2;
	gl_begin(GL_LINE_LOOP);
	for (int i = 0; i < N; ++i) {
		gl_vertex_3f(x + 2*tan(t), y + 2*cos(t)*cos(t), 0.0f);
		t += PI/N;
	}
	gl_end();
}

}

#endif