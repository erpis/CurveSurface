#include "opengl_impl.h"
#include "render_engine.h"

opengl_impl::opengl_impl(double x, double y, double radius)
	:center_x(x), center_y(y), R(radius) {
	draw_behavior = render_engine::draw_astroid;
}

void opengl_impl::draw() {
	gl_clear(GL_COLOR_BUFFER_BIT);
	gl_color_3f(1.0, 0.0, 0.0);
	draw_behavior(center_x, center_y, R, 1000);
	gl_flush();
}

void opengl_impl::resize(int w, int h) {
	gl_viewport(0, 0, w, h);
	gl_matrix_mode(GL_PROJECTION);
	gl_load_identity();
	gl_ortho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	gl_matrix_mode(GL_MODELVIEW);
	gl_load_identity();
}

void opengl_impl::keyboard_handler(unsigned char key, int x, int y) {
	switch (key) {
		case 27:
			exit(0);
			break;

		case '1':
			draw_behavior = render_engine::draw_astroid;
			break;

		case '2':
			draw_behavior = render_engine::draw_circle;
			break;

		case '3':
			draw_behavior = render_engine::draw_leminiscate_of_bernoulli;
			break;

		case '4':
			draw_behavior = render_engine::draw_witch_of_agnesi;
			break;

		default:
			break;
	}
	glut_post_redisplay();
}
