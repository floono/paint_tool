#ifndef SHADER_TOOLS_H
#define SHADER_TOOLS_H

typedef struct 
{
    unsigned int id;
    unsigned int vert_id;
    unsigned int frag_id;
} ShaderProgram;

ShaderProgram setupShaders(char* vertSrcDir, char* fragSrcDir);

#endif