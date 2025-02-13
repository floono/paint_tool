#version 430 core

in vec2 v_texcoord;
out vec4 f_colour;

uniform sampler2D u_layer_texture;

void main()
{
    f_colour = texture(u_layer_texture, v_texcoord);
}