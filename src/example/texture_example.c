#define GLIB_IMPLEMENTATION
#include "../glib.h"

glib_obj_t* triangle_obj;
unsigned int texture;

void render(void){
    glib_use_texture_2d(texture, GLIB_TEX_SLOT0);
    glib_draw_obj(triangle_obj);
}

int main(){
    glib_init();
    glib_create_window(900, 600, "GLib window");
    glib_clear_color(0.0f, 0.3f, 1.0f, 1.0f);
    glib_set_render_callback(render);

    texture = glib_load_texture_2d("./resources/textures/wall.jpg", 0);
    triangle_obj = glib_create_triangle_obj(0.0f,  0.5f, 0.5f, -0.5f, -0.5f,-0.5f);

    glib_main_loop();
    return 0;
}