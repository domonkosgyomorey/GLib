/*
    @file glib.h

    @author Gyömörey Domonkos https://github.com/domonkosgyomorey

    @version 0.1

    A simple header only graphical library overlay based on OpenGL, GLFW, GLEW

    @copyright
    Copyright 2023 Gyömörey Domonkos

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
    associated documentation files (the “Software”), to deal in the Software without restriction, 
    including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
    and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
    subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial 
    portions of the Software.

    THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
    BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/



#ifndef GLiB_H
#define GLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <cglm/cglm.h>

#define FAST_OBJ_IMPLEMENTATION
#include "fast_obj.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GLIB_ARRAY_LEN(ARR) (sizeof(ARR)/sizeof(ARR[0]))
#define GLIB_HEX_TO_RGBA_F(H) ((H>>24)&0xFF)/255.0f, ((H>>16)&0xFF)/255.0f, ((H>>8)&0xFF)/255.0f, ((H>>0)&0xFF)/255.0f

#define GLIB_SUPPORTED_VERTICES  30000
#define GLIB_SUPPORTED_UVS       30000
#define GLIB_SUPPORTED_NORMALS   30000

#define GLIB_MAX_KEYBOARD_KEY_SUPPORTED 350
#define GLIB_MAX_MOUSE_BUTTON_SUPPORTED 8

#define GLIB_MOUSE_BUTTON_LEFT 0
#define GLIB_MOUSE_BUTTON_RIGHT 1
#define GLIB_MOUSE_BUTTON_MIDDLE 2
#define GLIB_MOUSE_BUTTON_LAST 8

#define 	GLIB_KEY_UNKNOWN   -1
#define 	GLIB_KEY_SPACE   32
#define 	GLIB_KEY_APOSTROPHE   39 /* ' */
#define 	GLIB_KEY_COMMA   44 /* , */
#define 	GLIB_KEY_MINUS   45 /* - */
#define 	GLIB_KEY_PERIOD   46 /* . */
#define 	GLIB_KEY_SLASH   47 /* / */
#define 	GLIB_KEY_0   48
#define 	GLIB_KEY_1   49
#define 	GLIB_KEY_2   50
#define 	GLIB_KEY_3   51
#define 	GLIB_KEY_4   52
#define 	GLIB_KEY_5   53
#define 	GLIB_KEY_6   54
#define 	GLIB_KEY_7   55
#define 	GLIB_KEY_8   56
#define 	GLIB_KEY_9   57
#define 	GLIB_KEY_SEMICOLON   59 /* ; */
#define 	GLIB_KEY_EQUAL   61 /* = */
#define 	GLIB_KEY_A   65
#define 	GLIB_KEY_B   66
#define 	GLIB_KEY_C   67
#define 	GLIB_KEY_D   68
#define 	GLIB_KEY_E   69
#define 	GLIB_KEY_F   70
#define 	GLIB_KEY_G   71
#define 	GLIB_KEY_H   72
#define 	GLIB_KEY_I   73
#define 	GLIB_KEY_J   74
#define 	GLIB_KEY_K   75
#define 	GLIB_KEY_L   76
#define 	GLIB_KEY_M   77
#define 	GLIB_KEY_N   78
#define 	GLIB_KEY_O   79
#define 	GLIB_KEY_P   80
#define 	GLIB_KEY_Q   81
#define 	GLIB_KEY_R   82
#define 	GLIB_KEY_S   83
#define 	GLIB_KEY_T   84
#define 	GLIB_KEY_U   85
#define 	GLIB_KEY_V   86
#define 	GLIB_KEY_W   87
#define 	GLIB_KEY_X   88
#define 	GLIB_KEY_Y   89
#define 	GLIB_KEY_Z   90
#define 	GLIB_KEY_LEFT_BRACKET   91 /* [ */
#define 	GLIB_KEY_BACKSLASH   92 /* \ */
#define 	GLIB_KEY_RIGHT_BRACKET   93 /* ] */
#define 	GLIB_KEY_GRAVE_ACCENT   96 /* ` */
#define 	GLIB_KEY_WORLD_1   161 /* non-US #1 */
#define 	GLIB_KEY_WORLD_2   162 /* non-US #2 */
#define 	GLIB_KEY_ESCAPE   256
#define 	GLIB_KEY_ENTER   257
#define 	GLIB_KEY_TAB   258
#define 	GLIB_KEY_BACKSPACE   259
#define 	GLIB_KEY_INSERT   260
#define 	GLIB_KEY_DELETE   261
#define 	GLIB_KEY_RIGHT   262
#define 	GLIB_KEY_LEFT   263
#define 	GLIB_KEY_DOWN   264
#define 	GLIB_KEY_UP   265
#define 	GLIB_KEY_PAGE_UP   266
#define 	GLIB_KEY_PAGE_DOWN   267
#define 	GLIB_KEY_HOME   268
#define 	GLIB_KEY_END   269
#define 	GLIB_KEY_CAPS_LOCK   280
#define 	GLIB_KEY_SCROLL_LOCK   281
#define 	GLIB_KEY_NUM_LOCK   282
#define 	GLIB_KEY_PRINT_SCREEN   283
#define 	GLIB_KEY_PAUSE   284
#define 	GLIB_KEY_F1   290
#define 	GLIB_KEY_F2   291
#define 	GLIB_KEY_F3   292
#define 	GLIB_KEY_F4   293
#define 	GLIB_KEY_F5   294
#define 	GLIB_KEY_F6   295
#define 	GLIB_KEY_F7   296
#define 	GLIB_KEY_F8   297
#define 	GLIB_KEY_F9   298
#define 	GLIB_KEY_F10   299
#define 	GLIB_KEY_F11   300
#define 	GLIB_KEY_F12   301
#define 	GLIB_KEY_F13   302
#define 	GLIB_KEY_F14   303
#define 	GLIB_KEY_F15   304
#define 	GLIB_KEY_F16   305
#define 	GLIB_KEY_F17   306
#define 	GLIB_KEY_F18   307
#define 	GLIB_KEY_F19   308
#define 	GLIB_KEY_F20   309
#define 	GLIB_KEY_F21   310
#define 	GLIB_KEY_F22   311
#define 	GLIB_KEY_F23   312
#define 	GLIB_KEY_F24   313
#define 	GLIB_KEY_F25   314
#define 	GLIB_KEY_KP_0   320
#define 	GLIB_KEY_KP_1   321
#define 	GLIB_KEY_KP_2   322
#define 	GLIB_KEY_KP_3   323
#define 	GLIB_KEY_KP_4   324
#define 	GLIB_KEY_KP_5   325
#define 	GLIB_KEY_KP_6   326
#define 	GLIB_KEY_KP_7   327
#define 	GLIB_KEY_KP_8   328
#define 	GLIB_KEY_KP_9   329
#define 	GLIB_KEY_KP_DECIMAL   330
#define 	GLIB_KEY_KP_DIVIDE   331
#define 	GLIB_KEY_KP_MULTIPLY   332
#define 	GLIB_KEY_KP_SUBTRACT   333
#define 	GLIB_KEY_KP_ADD   334
#define 	GLIB_KEY_KP_ENTER   335
#define 	GLIB_KEY_KP_EQUAL   336
#define 	GLIB_KEY_LEFT_SHIFT   340
#define 	GLIB_KEY_LEFT_CONTROL   341
#define 	GLIB_KEY_LEFT_ALT   342
#define 	GLIB_KEY_LEFT_SUPER   343
#define 	GLIB_KEY_RIGHT_SHIFT   344
#define 	GLIB_KEY_RIGHT_CONTROL   345
#define 	GLIB_KEY_RIGHT_ALT   346
#define 	GLIB_KEY_RIGHT_SUPER   347
#define 	GLIB_KEY_MENU   348
#define 	GLIB_KEY_LAST   GLIB_KEY_MENU

/*!
    @breif this struct stores some data for a whole object and used in renderering that
*/
typedef struct {
    float* vertices;
    unsigned int vertex_len;
    unsigned int* indices;
    unsigned int index_len;

    int VBO, EBO, VAO;
} glib_obj_t;


/*!
    @brief This enum contains the currently available texture slots. The slot 0 is the default texture slot which is used by default
*/
typedef enum {
    GLIB_TEX_SLOT0 = 0,
    GLIB_TEX_SLOT1,
    GLIB_TEX_SLOT2,
    GLIB_TEX_SLOT3,
    GLIB_TEX_SLOT4,
    GLIB_TEX_SLOT5,
    GLIB_TEX_SLOT6,
    GLIB_TEX_SLOT7,
    GLIB_TEX_SLOT8,
    GLIB_TEX_SLOT9,
    GLIB_TEX_SLOT10,
    GLIB_TEX_SLOT11,
    GLIB_TEX_SLOT12,
    GLIB_TEX_SLOT13,
    GLIB_TEX_SLOT14,
    GLIB_TEX_SLOT15,
    GLIB_TEX_SLOT16,
    GLIB_TEX_SLOT17,
    GLIB_TEX_SLOT_COUNT,
} glib_texture_slot;

typedef struct {
    vec3 position;
    vec3 front;
    vec3 up;
    vec3 right;
    vec3 world_up;
    
    float yaw;
    float pitch;

    float movement_speed;
    float mouse_sensitivity;
    float zoom;
} glib_camera_t;

/*!
    @brief Read content from a file into an allocated buffer

    @param file_name is the file path to the file

    @return The file content in an allocated cstr
*/
char* glib_read_from_file(const char* file_name);

/*!
    @brief Init OpenGL and other stuff
*/
void glib_init(void);

/*!
    @brief  Create a window

    @param width is the width of the window in pixels
    @param height is the height of the window in pixels
    @param title is the title of the window
*/
void glib_create_window(int width, int height, const char* title);

/*!
    @brief Set clear color

    @param r red    0-1
    @param g green  0-1
    @param b blue   0-1
    @param a alpha  0-1
*/
void glib_clear_color(float r, float g, float b, float a);

/*!
    @brief Accept a function which run every rendering frame. This function stores your own little rendering function

    @param glib_render_fun is a function format for a rendering fun
*/
void glib_set_render_callback(void (*glib_render_fun)(void));

/*!
    @brief Accept a function which run when the framebuffer change.

    @param glib_framebuffer_resize_fun is a function format for a rendering fun
*/
void glib_set_framebuffer_resize_callback(void (*glib_framebuffer_resize_fun)(int width, int height));

/*!
    @brief Chack if a key is pressed on the keyboard

    @param keycode the key what you want to check

    @return If the key is pressed than return true (1), otherwise false (0)
*/
bool glib_is_keboard_pressed(int keycode);

/*!
    @brief Chack if a mouse button is pressed

    @param mouse_button the button what you want to check

    @return If the button is pressed than return true (1), otherwise false (0)
*/
bool glib_is_mouse_pressed(int mouse_button);

/*!
    @brief Check if the mouse is dragging

    @return If the mouse dragging return true (1), otherwise false (0)
*/
bool glib_is_mouse_dragging(void);

/*!
    @brief Get the mouse X coordinate relative to the window

    @return Return the X coordinate of the mouse a window normalized way 
*/
double glib_get_mouse_pos_x(void);

/*!
    @brief Get the mouse Y coordinate relative to the window

    @return Return the Y coordinate of the mouse a window normalized way 
*/
double glib_get_mouse_pos_y(void);

/*!
    @brief Get what mouse button use for dragging

    @return that mouse button what you are using when drag
*/
int glib_get_mouse_drag_button(void);

/*!
    @brief Start the main loop and call the stored render function
*/
void glib_main_loop(void);

/*!
    @brief Create an object from your vertices and indices. This function also stores the VAO, VBO, EBO which is usefull for renderering this object

    @param vertices the pointer to your vertices array
    @param vertices_len the len of vertices array
    @param indices the pointer to your indices array
    @param indices_len the len of indices array

    @return The object struct which stores some data

*/
glib_obj_t* glib_create_obj(float* vertices, unsigned int vertices_len, unsigned int* indices, unsigned int indices_len);

/*!
    @brief Create an object from your vertices and indices. This function also stores the VAO, VBO, EBO which is usefull for renderering this object

    @param vertices the pointer to your vertices array
    @param vertices_len the len of vertices array

    @return The object struct which stores some data

*/
glib_obj_t* glib_create_obj_from_vert(float* vertices, unsigned int vertices_len);

/*!
    @brief Create a triangle object from coords

    @return The glib object reference which stores some data
*/
glib_obj_t* glib_create_triangle_obj(float x1, float y1, float x2, float y2, float x3, float y3);

/*!
    @brief Create a triangle object from coords

    @param rgba_hex A color format example r:255 g:0 b:0 a:255 => 0xFF0000FF

    @return The glib object reference which stores some data
*/
glib_obj_t* glib_create_triangle_obj_ex(float x1, float y1, float x2, float y2, float x3, float y3, int rgba_hex);

/*!
    @brief Create a quad object from coords

    @return The glib object reference which stores some data
*/
glib_obj_t* glib_create_quad_obj(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

/*!
    @brief Create a quad object from coords
    
    @param rgba_hex A color format example r:255 g:0 b:0 a:255 => 0xFF0000FF

    @return The glib object reference which stores some data
*/
glib_obj_t* glib_create_quad_obj_ex(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int rgba_hex);


/*!
    @brief Load models with OBJ file format

    @param file_path the path to your model
*/
glib_obj_t* glib_load_obj(const char* file_path);

/*!
    @brief  Draw triangles using an glib obj

    @param obj is the glib obj
*/
void glib_draw_obj(glib_obj_t* obj);

/*!
    @brief Draw just the frame around an object
*/
void glib_wired_draw(void);

/*!
    @brief Draw the filled shape
*/
void glib_filled_draw(void);

/*!
    @brief Create a shader program from file

    @param vert_file_path is the file path to your vertex shader file
    @param frag_file_path is the file path to your fragment shader file

    @return The shader program ID
*/
unsigned int glib_create_shader(const char* vert_file_path, const char* frag_file_path);

/*!
    @brief Create a shader program from memory

    @param vert_src is the vertex source code
    @param frag_src is the fragment source code

    @return The shader program ID
*/
unsigned int glib_create_shader_from_memory(const char* vert_src, const char* frag_src);

/*!
    @brief Apply shader for the further objects

    @param shader_id is the ID of your shader program
*/
void glib_use_shader(int shader_id);

/*!
    @brief Upload int value into a shader

    @param program_id is your shader program ID
    @param name is the uniform name in the shader
    @param value is the value which will be upload into yout uniform
*/ 
void glib_set_uniform1i(int program_id, const char* name, int value);

/*!
    @brief Upload float value into a shader

    @param program_id is your shader program ID
    @param name is the uniform name in the shader
    @param value is the value which will be upload into yout uniform
*/ 
void glib_set_uniform1f(int program_id, const char* name, float value);

/*!
    @brief Upload double value into a shader

    @param program_id is your shader program ID
    @param name is the uniform name in the shader
    @param value is the value which will be upload into yout uniform
*/ 
void glib_set_uniform1d(int program_id, const char* name, double value);

/*!
    @brief Upload matrix 4x4 value into a shader

    @param program_id is your shader program ID
    @param name is the uniform name in the shader
    @param value is the value which will be upload into yout uniform
*/ 
void glib_set_unifrom_mat4(int program_id, const char* name, mat4 value);

/*!
    @brief Load 2D texture from file. This 2D texture loader only work with the following color channel formats: RGBA, RGB 

    @param file_path is your file path into the texture
    @param has_alpha which indicate if your texture has alpha channel

    @return The loaded texture ID
*/
unsigned int glib_load_texture_2d(const char* file_path, unsigned char has_alpha);

/*!
    @brief Load 2D texture from memory. This 2D texture loader only work with the following color channel formats: RGBA, RGB 

    @param raw_data is your raw texture data
    @param data_len the length of your raw texture
    @param has_alpha which indicate if your texture has alpha channel

    @return The loaded texture ID
*/
unsigned int glib_load_texture_2d_from_memory(const char* raw_data, unsigned int data_len, unsigned char has_alpha);

/*!
    @brief Activate and use a texture. The texture slot 0 is not available, bacause the library use it for the default texture

    @param texure is the texure ID
    @param slot is the slot number where your put the shader. The following slots are available: See above in the glib_texture_slot enum
*/
void glib_use_texture_2d(unsigned int texture, glib_texture_slot slot);

#ifdef GLIB_IMPLEMENTATION

const char glib_default_tex_jpg_raw[] = {0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01, 0x01, 0x01, 0x00, 0x60, 
0x00, 0x60, 0x00, 0x00, 0xFF, 0xDB, 0x00, 0x43, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x02, 
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x05, 0x03, 0x03, 0x03, 0x03, 0x03, 0x06, 0x04, 
0x04, 0x03, 0x05, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x08, 0x09, 0x0B, 0x09, 0x08, 
0x08, 0x0A, 0x08, 0x07, 0x07, 0x0A, 0x0D, 0x0A, 0x0A, 0x0B, 0x0C, 0x0C, 0x0C, 0x0C, 0x07, 0x09, 
0x0E, 0x0F, 0x0D, 0x0C, 0x0E, 0x0B, 0x0C, 0x0C, 0x0C, 0xFF, 0xDB, 0x00, 0x43, 0x01, 0x02, 0x02, 
0x02, 0x03, 0x03, 0x03, 0x06, 0x03, 0x03, 0x06, 0x0C, 0x08, 0x07, 0x08, 0x0C, 0x0C, 0x0C, 0x0C, 
0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 
0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 
0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0xFF, 0xC0, 
0x00, 0x11, 0x08, 0x00, 0x01, 0x00, 0x01, 0x03, 0x01, 0x22, 0x00, 0x02, 0x11, 0x01, 0x03, 0x11, 
0x01, 0xFF, 0xC4, 0x00, 0x1F, 0x00, 0x00, 0x01, 0x05, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 
0x0A, 0x0B, 0xFF, 0xC4, 0x00, 0xB5, 0x10, 0x00, 0x02, 0x01, 0x03, 0x03, 0x02, 0x04, 0x03, 0x05, 
0x05, 0x04, 0x04, 0x00, 0x00, 0x01, 0x7D, 0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12, 0x21, 
0x31, 0x41, 0x06, 0x13, 0x51, 0x61, 0x07, 0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xA1, 0x08, 0x23, 
0x42, 0xB1, 0xC1, 0x15, 0x52, 0xD1, 0xF0, 0x24, 0x33, 0x62, 0x72, 0x82, 0x09, 0x0A, 0x16, 0x17, 
0x18, 0x19, 0x1A, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 
0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 
0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 
0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 
0x9A, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 
0xB8, 0xB9, 0xBA, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xD2, 0xD3, 0xD4, 0xD5, 
0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xF1, 
0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFF, 0xC4, 0x00, 0x1F, 0x01, 0x00, 0x03, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0xFF, 0xC4, 0x00, 0xB5, 0x11, 0x00, 
0x02, 0x01, 0x02, 0x04, 0x04, 0x03, 0x04, 0x07, 0x05, 0x04, 0x04, 0x00, 0x01, 0x02, 0x77, 0x00, 
0x01, 0x02, 0x03, 0x11, 0x04, 0x05, 0x21, 0x31, 0x06, 0x12, 0x41, 0x51, 0x07, 0x61, 0x71, 0x13, 
0x22, 0x32, 0x81, 0x08, 0x14, 0x42, 0x91, 0xA1, 0xB1, 0xC1, 0x09, 0x23, 0x33, 0x52, 0xF0, 0x15, 
0x62, 0x72, 0xD1, 0x0A, 0x16, 0x24, 0x34, 0xE1, 0x25, 0xF1, 0x17, 0x18, 0x19, 0x1A, 0x26, 0x27, 
0x28, 0x29, 0x2A, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 
0x4A, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 
0x6A, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 
0x89, 0x8A, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 
0xA7, 0xA8, 0xA9, 0xAA, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xC2, 0xC3, 0xC4, 
0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xE2, 
0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 
0xFA, 0xFF, 0xDA, 0x00, 0x0C, 0x03, 0x01, 0x00, 0x02, 0x11, 0x03, 0x11, 0x00, 0x3F, 0x00, 0xFD, 
0xFC, 0xA2, 0x8A, 0x28, 0x03, 0xFF, 0xD9};

const char* glib_default_vert = {
    "#version 330 core\n"
    "layout (location = 0) in vec3 pos;\n"
    "layout (location = 1) in vec4 col;\n"
    "layout (location = 2) in vec2 tex_coord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 proj;\n"
    "out vec4 b_col;\n"
    "out vec2 b_tex_coord;\n"
    "void main(){\n"
        "b_col = col;\n"
        "b_tex_coord = tex_coord;\n"
        "gl_Position = proj*view*model*vec4(pos, 1.0);\n"
    "}\n"
};

const char* glib_default_frag = {
    "#version 330 core\n"
    "in vec4 b_col;\n"
    "in vec2 b_tex_coord;\n"
    "uniform sampler2D tex0;\n"
    "out vec4 FragColor;\n"
    "void main(){\n"
        "FragColor = texture(tex0, b_tex_coord)*b_col;\n"
    "}\n"
};

GLFWwindow* glib_window;

unsigned int glib_window_width;
unsigned int glib_window_height;

void (*glib_render_fun)(void) = NULL;
void (*glib_framebuffer_resize_fun)(int width, int height) = NULL;

unsigned int glib_default_tex;

unsigned int glib_default_shader;

bool glib_keyboard_pressed[GLIB_MAX_KEYBOARD_KEY_SUPPORTED];
bool glib_mouse_pressed[GLIB_MAX_MOUSE_BUTTON_SUPPORTED];
bool glib_mouse_dragging;
int glib_mouse_drag_button;
double glib_mouse_pos_x;
double glib_mouse_pos_y;

const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;

char* glib_read_from_file(const char* file_name){
    FILE *fp;
    long size;
    char *buffer;

    fp = fopen ( file_name , "rb" );
    if( !fp ) perror(file_name),exit(1);

    fseek( fp , 0L , SEEK_END);
    size = ftell( fp );
    rewind( fp );

    buffer = calloc( 1, size+1 );
    if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    if( 1!=fread( buffer , size, 1 , fp) )
        fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);

    fclose(fp);
    return buffer;
}

void glib_init(void){
    if(!glfwInit()){
        fprintf(stderr, "ERROR: cannot init glfw\n");
        exit(-1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    printf("[INFO] %s\n", glfwGetVersionString());
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    printf("[INFO] Maximum nr of vertex attributes supported: %zu\n", nrAttributes);
}

static void glib_framebuff_resize(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
    if(glib_framebuffer_resize_fun!=NULL){
        glib_framebuffer_resize_fun(width, height);
    }
    glib_window_width = width;
    glib_window_height = height;
}

static void glib_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(action==GLFW_PRESS){
        glib_keyboard_pressed[key] = true;
    }else if(action==GLFW_RELEASE){
        glib_keyboard_pressed[key] = false;
    }
}

static void glib_cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    glib_mouse_pos_x = xpos;
    glib_mouse_pos_y = ypos;
}

static void glib_mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    if(action==GLFW_PRESS){
        glib_mouse_pressed[button] = true;
        if(!glib_mouse_dragging){
            glib_mouse_dragging = true;
            glib_mouse_drag_button = button;
        }
    }else if(action==GLFW_RELEASE){
        glib_mouse_pressed[button] = false;
        if(button==glib_mouse_drag_button){
            glib_mouse_dragging = false;
        }
    }
}

void glib_create_window(int width, int height, const char* title){
    if(!(glib_window = glfwCreateWindow(width, height, title, NULL, NULL))){
        fprintf(stderr, "ERROR: cannot create window\n");
        exit(-1);
    }

    glfwMakeContextCurrent(glib_window);
    GLenum err = glewInit();
    if (GLEW_OK != err){
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        exit(-1);
    }

    glfwSetFramebufferSizeCallback(glib_window, glib_framebuff_resize);
    glib_window_width = width;
    glib_window_height = height;

    glfwSetKeyCallback(glib_window, glib_key_callback);
    glfwSetCursorPosCallback(glib_window, glib_cursor_position_callback);
    glfwSetMouseButtonCallback(glib_window, glib_mouse_button_callback);
    
    glib_default_shader = glib_create_shader_from_memory(glib_default_vert, glib_default_frag);

    glib_default_tex = glib_load_texture_2d_from_memory(glib_default_tex_jpg_raw, GLIB_ARRAY_LEN(glib_default_tex_jpg_raw), 0);
    glEnable(GL_DEPTH_TEST);
}

void glib_clear_color(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
}

void glib_set_render_callback(void (*render_fun)(void)){
    glib_render_fun = render_fun;
}

void glib_set_framebuffer_resize_callback(void (*framebuffer_resize_fun)(int width, int height)){
    glib_framebuffer_resize_fun =  framebuffer_resize_fun;
}

bool glib_is_keboard_pressed(int keycode){
    if(keycode<GLIB_MAX_KEYBOARD_KEY_SUPPORTED){
        return glib_keyboard_pressed[keycode];
    }
    return false;
}

bool glib_is_mouse_pressed(int mouse_button){
    if(mouse_button<GLIB_MAX_MOUSE_BUTTON_SUPPORTED){
        return glib_mouse_pressed[mouse_button];
    }
    return false;
}

bool glib_is_mouse_dragging(void){
    return glib_mouse_dragging;
}

int glib_get_mouse_drag_button(void){
    return glib_mouse_drag_button;
}

double glib_get_mouse_pos_x(void){
    return (glib_mouse_pos_x/(double)glib_window_width)*2.0-1.0;
}

double glib_get_mouse_pos_y(void){
    return (glib_mouse_pos_y/(double)glib_window_height)*2.0-1.0;
}

void glib_main_loop(void){
    while(!glfwWindowShouldClose(glib_window)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glib_use_texture_2d(glib_default_tex, GLIB_TEX_SLOT0);
        glib_use_shader(glib_default_shader);
        if(glib_render_fun!=NULL){
            glib_render_fun();
        }

        glfwPollEvents();
        glfwSwapBuffers(glib_window);

    }
    glfwDestroyWindow(glib_window);
    glfwTerminate();
}

glib_obj_t* glib_create_obj(float* vertices, unsigned int vertices_len, unsigned int* indices, unsigned int indices_len){
    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices_len, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*indices_len, indices, GL_STATIC_DRAW);
    // Coord
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    // Texture
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    glib_obj_t* obj = (glib_obj_t*)malloc(sizeof(glib_obj_t));
    obj->VAO = VAO;
    obj->VBO = VBO;
    obj->EBO = EBO;
    obj->vertices = vertices;
    obj->vertex_len = vertices_len;
    obj->indices = indices;
    obj->index_len = indices_len;
    return obj;
}

glib_obj_t* glib_create_obj_from_vert(float* vertices, unsigned int vertices_len){
    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices_len, vertices, GL_STATIC_DRAW);

    // Coord
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    // Texture
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    glib_obj_t* obj = (glib_obj_t*)malloc(sizeof(glib_obj_t));
    obj->VAO = VAO;
    obj->VBO = VBO;
    obj->vertices = vertices;
    obj->vertex_len = vertices_len;
    return obj;
}

glib_obj_t* glib_create_triangle_obj(float x1, float y1, float x2, float y2, float x3, float y3){
    float vertices[] = {
        x1, y1, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, x1, y1,
        x2, y2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, x2, y2,
        x3, y3, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, x3, y3,
    };
    
    unsigned int indices[] = {
        0, 1, 2
    };

    return glib_create_obj(vertices, GLIB_ARRAY_LEN(vertices), indices, GLIB_ARRAY_LEN(indices));
}
glib_obj_t* glib_create_triangle_obj_ex(float x1, float y1, float x2, float y2, float x3, float y3, int rgba_hex){
    float vertices[] = {
        x1, y1, 0.0f, GLIB_HEX_TO_RGBA_F(rgba_hex), x1, y1,
        x2, y2, 0.0f, GLIB_HEX_TO_RGBA_F(rgba_hex), x2, y2,
        x3, y3, 0.0f, GLIB_HEX_TO_RGBA_F(rgba_hex), x3, y3,
    };
    
    unsigned int indices[] = {
        0, 1, 2
    };

    return glib_create_obj(vertices, GLIB_ARRAY_LEN(vertices), indices, GLIB_ARRAY_LEN(indices));
}

glib_obj_t* glib_create_quad_obj(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
    float vertices[] = {
        x1, y1, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, x1, y1,
        x2, y2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, x2, y2,
        x3, y3, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, x3, y3,
        x4, y4, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, x4, y4,
    };
    
    unsigned int indices[] = {
        0, 1, 2,
        0, 2, 3,
    };

    return glib_create_obj(vertices, GLIB_ARRAY_LEN(vertices), indices, GLIB_ARRAY_LEN(indices));
}
glib_obj_t* glib_create_quad_obj_ex(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int rgba_hex){
    float vertices[] = {
        x1, y1, 0.0f, GLIB_HEX_TO_RGBA_F(rgba_hex), x1, y1,
        x2, y2, 0.0f, GLIB_HEX_TO_RGBA_F(rgba_hex), x2, y2,
        x3, y3, 0.0f, GLIB_HEX_TO_RGBA_F(rgba_hex), x3, y3,
        x4, y4, 0.0f, GLIB_HEX_TO_RGBA_F(rgba_hex), x4, y4,
    };
    
    unsigned int indices[] = {
        0, 1, 2,
        0, 2, 3,
    };

    return glib_create_obj(vertices, GLIB_ARRAY_LEN(vertices), indices, GLIB_ARRAY_LEN(indices));
}

void glib_draw_obj(glib_obj_t* obj){
    glBindVertexArray(obj->VAO);
    if(obj->index_len==0){
        glDrawArrays(GL_TRIANGLES, 0, obj->vertex_len);
    }else{
        glDrawElements(GL_TRIANGLES, obj->index_len, GL_UNSIGNED_INT, 0);
    }
}

void glib_wired_draw(){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void glib_filled_draw(){
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int compile_shader(GLenum shader_type, const char* shader_thing, int from_memory){
    GLint is_compiled = 0;
    /* Calls the Function that loads the Shader source code from a file */
    const char* shader_source;
    if(from_memory){
        shader_source = shader_thing;
        printf("%s\n", shader_source);
    }else{
        shader_source = glib_read_from_file(shader_thing); 
        printf("%s: %s\n", shader_thing, shader_source);
    }

    int shader_id = glCreateShader(shader_type);
    if(shader_id == 0) {
        printf("COULD NOT LOAD SHADER: %s!\n", from_memory?shader_thing:"");
        exit(-1);
    }

    glShaderSource(shader_id, 1, (const char**)&shader_source, NULL);
    glCompileShader(shader_id);
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &is_compiled);

    if(is_compiled == GL_FALSE) {
        GLint max_len = 0;
        char info_log[1024];
	    glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &max_len);
        glGetShaderInfoLog(shader_id, max_len, &max_len, info_log);

        printf("%s\n", info_log);
        fprintf(stderr, "Shader Compiler Error: %s\n", from_memory?shader_thing:"");
        glDeleteShader(shader_id);
        exit(-1);
    }

    return shader_id;
}

int link_shader(GLuint vertex_shader_id, GLuint fragment_shader_id){
    GLuint program_id = 0;
    GLint is_linked = 0;
    GLint max_len = 0;
    char info_log[1024];

    program_id = glCreateProgram();

    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);

    glLinkProgram(program_id);

    glGetProgramiv(program_id, GL_LINK_STATUS, &is_linked);
    if(is_linked == GL_FALSE) {
        printf("Shader Program Linker Error\n");
        
	    glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &max_len);
        glGetProgramInfoLog(program_id, max_len, &max_len, info_log);

        printf("%s\n", info_log);

        glDeleteProgram(program_id);

        glDeleteShader(vertex_shader_id);
        glDeleteShader(fragment_shader_id);

        exit(-1);
    }

    glDetachShader(program_id, vertex_shader_id);
    glDetachShader(program_id, fragment_shader_id);

    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);

    return program_id;
}

unsigned int glib_create_shader(const char* vert_file_path, const char* frag_file_path){
    GLuint vert_id = compile_shader(GL_VERTEX_SHADER, vert_file_path, 0);
    GLuint frag_id = compile_shader(GL_FRAGMENT_SHADER, frag_file_path, 0);
    
    return link_shader(vert_id, frag_id);
}

unsigned int glib_create_shader_from_memory(const char* vert_src, const char* frag_src){
    GLuint vert_id = compile_shader(GL_VERTEX_SHADER, vert_src, 1);
    GLuint frag_id = compile_shader(GL_FRAGMENT_SHADER, frag_src, 1);
    
    return link_shader(vert_id, frag_id);
}

void glib_use_shader(int shader_id){
    glUseProgram(shader_id);
}

void glib_set_uniform1i(int program_id, const char* name, int value){
    glUniform1i(glGetUniformLocation(program_id, name), value);
}

void glib_set_uniform1f(int program_id, const char* name, float value){
    glUniform1f(glGetUniformLocation(program_id, name), value);
}

void glib_set_uniform1d(int program_id, const char* name, double value){
    glUniform1d(glGetUniformLocation(program_id, name), value);
}

void glib_set_unifrom_mat4(int program_id, const char* name, mat4 value){
    glUniformMatrix4fv(glGetUniformLocation(program_id, name), 1, GL_FALSE, (float*)value);
}

unsigned int glib_load_texture_2d(const char* file_path, unsigned char has_alpha){
    unsigned int tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, n_channels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load(file_path, &width, &height, &n_channels, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D, 0, has_alpha?GL_RGBA:GL_RGB, width, height, 0, has_alpha?GL_RGBA:GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        fprintf(stderr, "Failed to load texture. %s\n", file_path);
        exit(-1);
    }
    stbi_image_free(data);

    return tex;
}

unsigned int glib_load_texture_2d_from_memory(const char* raw_data, unsigned int data_len, unsigned char has_alpha){
    unsigned int tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, n_channels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load_from_memory(raw_data, data_len, &width, &height, &n_channels, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D, 0, has_alpha?GL_RGBA:GL_RGB, width, height, 0, has_alpha?GL_RGBA:GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        fprintf(stderr, "Failed to load texture. %p\n", raw_data);
        exit(-1);
    }
    stbi_image_free(data);

    return tex;
}

void glib_use_texture_2d(unsigned int texture, glib_texture_slot slot){
    switch(slot){
        case GLIB_TEX_SLOT0:
        glActiveTexture(GL_TEXTURE0);
        break;
        case GLIB_TEX_SLOT1:
        glActiveTexture(GL_TEXTURE1);
        break;
        case GLIB_TEX_SLOT2:
        glActiveTexture(GL_TEXTURE2);
        break;
        case GLIB_TEX_SLOT3:
        glActiveTexture(GL_TEXTURE3);
        break;
        case GLIB_TEX_SLOT4:
        glActiveTexture(GL_TEXTURE4);
        break;
        case GLIB_TEX_SLOT5:
        glActiveTexture(GL_TEXTURE5);
        break;
        case GLIB_TEX_SLOT6:
        glActiveTexture(GL_TEXTURE6);
        break;
        case GLIB_TEX_SLOT7:
        glActiveTexture(GL_TEXTURE7);
        break;
        case GLIB_TEX_SLOT8:
        glActiveTexture(GL_TEXTURE8);
        break;
        case GLIB_TEX_SLOT9:
        glActiveTexture(GL_TEXTURE9);
        break;
        case GLIB_TEX_SLOT10:
        glActiveTexture(GL_TEXTURE10);
        break;
        case GLIB_TEX_SLOT11:
        glActiveTexture(GL_TEXTURE11);
        break;
        case GLIB_TEX_SLOT12:
        glActiveTexture(GL_TEXTURE12);
        break;
        case GLIB_TEX_SLOT13:
        glActiveTexture(GL_TEXTURE13);
        break;
        case GLIB_TEX_SLOT14:
        glActiveTexture(GL_TEXTURE14);
        break;
        case GLIB_TEX_SLOT15:
        glActiveTexture(GL_TEXTURE15);
        break;
        case GLIB_TEX_SLOT16:
        glActiveTexture(GL_TEXTURE16);
        break;
        case GLIB_TEX_SLOT17:
        glActiveTexture(GL_TEXTURE17);
        break;
        default:
        glActiveTexture(GL_TEXTURE0);
    }

    glBindTexture(GL_TEXTURE_2D, texture);
}

#endif //GLIB_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // GLIB_H