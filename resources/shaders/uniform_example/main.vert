#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 col;

out vec3 b_pos;
out vec3 b_col;

void main(){
    b_pos = pos;
    b_col = col;
    gl_Position = vec4(pos, 1.0);
}