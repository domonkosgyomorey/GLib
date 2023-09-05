#define GLIB_IMPLEMENTATION
#include "glib.h"
#include <stdio.h>

#include <cglm/cglm.h>

glib_obj_t* tri;
unsigned int texture;
void render(void){
    
    glib_use_texture_2d(texture, GLIB_TEX_SLOT0);

    glib_filled_draw();
    glib_draw_obj(tri);
}

void resize(int width, int height){
    printf("The new size of window: %zux%zu\n", width, height);
}

int main(int argc, char**argv){
    glib_init();
    glib_create_window(900, 600, "Hi!");
    glib_set_render_callback(render);
    glib_set_framebuffer_resize_callback(resize);
    
    tri = glib_create_triangle_obj(0.0f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f);
    texture = glib_load_texture_2d("./resources/textures/wall.jpg", 0);    

    glib_main_loop();
    
    printf("done!\n");
    return  0;
}