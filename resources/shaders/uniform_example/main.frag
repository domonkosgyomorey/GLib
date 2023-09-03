#version 330 core

in vec3 b_pos;
in vec3 b_col;

uniform float time;

out vec4 frag_c;

void main(){
    frag_c = vec4(b_col*abs((log(time)*sin((b_pos+time))))%b_pos, 1.0);
}