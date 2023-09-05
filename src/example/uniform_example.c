#define GLIB_IMPLEMENTATION
#include "../glib.h"

glib_obj_t* triangle_obj;
unsigned int my_shader;

void render(void){
    glib_use_shader(my_shader);
    glib_set_uniform1f(my_shader, "time", (float)glfwGetTime());
    glib_draw_obj(triangle_obj);
}

int main(){
    glib_init();
    glib_create_window(900, 600, "GLib window");
    glib_clear_color(0.0f, 0.3f, 1.0f, 1.0f);
    glib_set_render_callback(render);

    my_shader = glib_create_shader("./resources/shaders/uniform_example/main.vert", "./resources/shaders/uniform_example/main.frag");
    triangle_obj = glib_create_triangle_obj(0.0f,  0.5f, 0.5f, -0.5f, -0.5f,-0.5f);


    glib_main_loop();
    return 0;
}