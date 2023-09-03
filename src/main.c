#define GLIB_IMPLEMENTATION
#include "glib.h"
#include <stdio.h>

#include <cglm/cglm.h>

glib_obj_t* tri;
glib_obj_t* tri1;
unsigned int program;
unsigned int texture;
mat4 model;
mat4 view;
mat4 proj;
void render(void){
    
    glib_use_texture_2d(texture, GLIB_TEX_SLOT1);
    glib_use_shader(program);
    glib_set_uniform1i(program, "tex1", 1);

    glm_rotate(model, glfwGetTime(), (vec3){0.5f, 1.0f, 0.0f});
    glib_set_unifrom_mat4(program, "model", model);
    glib_set_unifrom_mat4(program, "view", view);
    glib_set_unifrom_mat4(program, "proj", proj);

    glib_filled_draw();
    glib_draw_triangles(tri);
    
    glib_wired_draw();
    glib_draw_triangles(tri1);
}

int main(int argc, char**argv){
    glib_init();
    glib_create_window(900, 600, "Hi!");
    glib_render_callback(render);
    
    float quad[] = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };
    unsigned int q_indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3,
    };

    float triangle[] = {
        -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -1.0f,  0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
         0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    };

    unsigned int t_indices[] = {
        0, 1, 2,  // first Triangle
    };
    
    program = create_shader("./resources/shaders/def.vert", "./resources/shaders/def.frag");
    tri = glib_create_obj(quad, 32, q_indices, 6);
    tri1 = glib_create_obj(triangle, 18, t_indices, 3);
    texture = glib_load_texture_2d("./resources/textures/wall.jpg", 0);    

    glm_mat4_identity(model);
    glm_rotate(model, glm_rad(-55), (vec3){1.0, 0.0, 0.0});
    glm_mat4_identity(view);
    glm_translate(view, (vec3){0.0, 0.0, -3.0});
    glm_mat4_identity(proj);
    glm_perspective(45, 800 / 600, 0.1, 100, proj);

    glib_main_loop();
    
    printf("done!\n");
    return  0;
}