#version 330 core

in vec3 b_col;
in vec2 b_tex_coord;

uniform sampler2D tex0;
uniform sampler2D tex1;

out vec4 FragColor;

void main(){
   FragColor = texture(tex1, b_tex_coord);
}