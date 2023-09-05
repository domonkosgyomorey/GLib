#define GLIB_IMPLEMENTATION
#include "../glib.h"

glib_obj_t* triangle_obj;

void render(void){
    glib_draw_obj(triangle_obj);
}

int main(){
    glib_init();
    glib_create_window(900, 600, "GLib window");
    glib_clear_color(0.0f, 0.3f, 1.0f, 1.0f);
    glib_set_render_callback(render);

    triangle_obj = glib_create_triangle_obj_ex(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0x6666BBFF);

    glib_main_loop();
    return 0;
}