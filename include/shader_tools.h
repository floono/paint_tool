#ifndef SHADER_TOOLS_H
#define SHADER_TOOLS_H

typedef struct
{
    unsigned int id;
    const char* src;
} Shader;

typedef struct 
{
    unsigned int id;
    Shader vert;
    Shader frag;
} ShaderProgram;

ShaderProgram setupShaders(char* vertSrcDir, char* fragSrcDir);

#endif