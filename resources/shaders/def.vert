#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 col;
layout (location = 2) in vec2 tex_coord;

out vec3 b_col; 
out vec2 b_tex_coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main(){
   b_col = col;
   b_tex_coord = tex_coord;
   gl_Position = proj*view*model*vec4(pos, 1.0);
}