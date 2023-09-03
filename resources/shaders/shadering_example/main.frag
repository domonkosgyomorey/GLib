#version 330 core

in vec3 b_pos;
in vec3 b_col;

out vec4 frag_c;

void main(){
    frag_c = (10*vec4(((b_col*b_col*b_col*b_col)%b_pos), 1.0));
}