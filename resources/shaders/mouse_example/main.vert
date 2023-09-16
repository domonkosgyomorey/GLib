#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 col;

uniform float time;
uniform float mouse_x;
uniform float mouse_y;

out vec3 b_pos;
out vec3 b_col;

void main(){
    b_pos = pos;
    b_col = col;
    gl_Position = vec4(pos, 1.0)-vec4(-mouse_x, mouse_y, 0.0, 0.0);
}