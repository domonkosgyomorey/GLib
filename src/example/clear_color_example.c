#define GLIB_IMPLEMENTATION
#include "../glib.h"

int main(){
    glib_init();
    glib_create_window(900, 600, "GLib window");
    glib_clear_color(0.5f, 0.7f, 0.1f, 1.0f);
    glib_main_loop();
    return 0;
}