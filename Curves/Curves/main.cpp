#include <cstdlib>
#include <iostream>
#include <cmath>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include "opengl_impl.h"

using namespace std;

opengl_impl gl;

	// Drawing routine.
void draw() {  
	gl.draw();
}

void setup() {
	gl_clear_color(1.0, 1.0, 1.0, 0.0); 
}

void resize(int w, int h) {
	gl.resize(w, h);	
}

void keyboard_handler(unsigned char key, int x, int y) {
	gl.keyboard_handler(key, x, y);	
}

int main(int argc, char **argv) {
	glut_init(&argc, argv);
	glut_init_display_mode(GLUT_SINGLE | GLUT_RGB); 
	glut_init_window_size(500, 500);
	glut_init_window_position(100, 100); 
	glut_create_window("curve");
	setup(); 
	glut_display_func(draw); 
	glut_reshape_func(resize);  
	glut_keyboard_func(keyboard_handler);
	glut_main_loop(); 

	return 0;
}
