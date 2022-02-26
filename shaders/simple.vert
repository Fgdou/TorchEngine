#version 450

layout (location = 0) in vec3 position;

uniform vec3 color;
out vec3 v_color;

void main(){
    v_color = color;
    gl_Position = vec4(position, 1.0f);
}