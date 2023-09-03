#define GLIB_IMPLEMENTATION
#include "../glib.h"

int main(){
    glib_init();
    glib_create_window(900, 600, "GLib window");
    glib_main_loop();
    return 0;
}