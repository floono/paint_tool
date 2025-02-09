#version 430 core

in vec2 frag_pos;
out vec4 frag_color;

uniform float time;

vec3 rainbow(float time) 
{
    float red = 0.5 + 0.5 * sin(time + 0.0);
    float green = 0.5 + 0.5 * sin(time + 2.0);
    float blue = 0.5 + 0.5 * sin(time + 4.0);

    return vec3(red, green, blue);
}

void main()
{
    frag_color = vec4(rainbow(time + frag_pos.x), 1.0);
}