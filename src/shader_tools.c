/* Standard Library Includes */
#include <stdio.h>
#include <stdlib.h>

/* OpenGL Library Includes */
#include <glad/glad.h>

/* SRC Header Includes */
#include <shader_tools.h>

char* readShader(char* filename)
{
    /* Opening file with error checking */
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        perror("fopen() failed in readShader() in shader_tools.c");
        return NULL;
    }

    /* Seeking to end of file with error checking */
    int seekResult = fseek(fp, 0, SEEK_END);
    if(seekResult != 0)
    {
        perror("fseek() failed in readShader() in shader_tools.c");
        fclose(fp);
        return NULL;
    }

    /* Obtaining location of file pointer at the end of the file with error checking */
    long fileSize = ftell(fp);
    if(fileSize == -1)
    {
        perror("ftell() failed in readShader() in shader_tools.c");
        fclose(fp);
        return NULL;
    }

    /* Return file pointer to beginning of file */
    rewind(fp);

    /* Allocating memory to store the file contents */
    char* fileContents = (char*)malloc(fileSize + 1); // +1 to include EOF
    if(fileContents == NULL)
    {
        perror("malloc() failed in readShader() in shader_tools.c");
        fclose(fp);
        return NULL;
    }
    
    size_t read = fread(fileContents, sizeof(char), fileSize, fp);
    if(read != fileSize)
    {
        perror("fread() failed in readShader() in shader_tools.c");
        free(fileContents);
        return NULL;
    }

    return fileContents;
}

ShaderProgram setupShaders(char* vertSrcDir, char* fragSrcDir)
{
    ShaderProgram program;

    /* Compiling Vertex Shader */
    program.vert.id = glCreateShader(GL_VERTEX_SHADER);
    program.vert.src = readShader(vertSrcDir);
    glShaderSource(program.vert.id, 1, &program.vert.src, NULL);
    glCompileShader(program.vert.id);

    /* Compiling Fragment Shader */
    program.frag.id = glCreateShader(GL_FRAGMENT_SHADER);
    program.frag.src = readShader(fragSrcDir);
    glShaderSource(program.frag.id, 1, &program.frag.src, NULL);
    glCompileShader(program.frag.id);

    /* Linking Shaders */
    program.id = glCreateProgram();
    glAttachShader(program.id, program.vert.id);
    glAttachShader(program.id, program.frag.id);
    glLinkProgram(program.id);

    /* Flagging the shaders for deletion once the shader program is destroyed */
    glDeleteShader(program.vert.id);
    glDeleteShader(program.frag.id);

    return program;
}