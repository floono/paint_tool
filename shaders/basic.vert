#version 430 core
layout(location = 0) in vec2 pos;

out vec2 frag_pos;

void main()
{
    frag_pos = pos;
    gl_Position = vec4(pos, 0.0, 1.0);
}