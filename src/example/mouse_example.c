#define GLIB_IMPLEMENTATION
#include "../glib.h"

glib_obj_t* quad_obj;
unsigned int my_shader;

float mouse_x,mouse_y;

void render(void){
    
    mouse_x = glib_get_mouse_pos_x();
    mouse_y = glib_get_mouse_pos_y();

    glib_use_shader(my_shader);
    glib_set_uniform1f(my_shader, "time", (float)glfwGetTime());

    if(glib_is_mouse_pressed(GLIB_MOUSE_BUTTON_LEFT)){
        glib_set_uniform1f(my_shader, "mouse_x", mouse_x);
        glib_set_uniform1f(my_shader, "mouse_y", mouse_y);

    }
    
    glib_draw_obj(quad_obj);
}

int main(){
    glib_init();
    glib_create_window(900, 600, "GLib window");
    glib_clear_color(0.0f, 0.3f, 1.0f, 1.0f);
    glib_set_render_callback(render);
    my_shader = glib_create_shader("./resources/shaders/mouse_example/main.vert", "./resources/shaders/mouse_example/main.frag");

    quad_obj = glib_create_quad_obj_ex(-0.5f,  0.5f, 0.5f, 0.5f, 0.5f,-0.5f, -0.5f,-0.5f, 0x6666BBFF);

    glib_main_loop();
    return 0;
}