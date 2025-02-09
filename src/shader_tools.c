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

    fclose(fp);
    fileContents[fileSize] = '\0';

    return fileContents;
}

ShaderProgram setupShaders(char* vertSrcDir, char* fragSrcDir)
{
    ShaderProgram program;

    /* Compiling Vertex Shader */
    program.vert_id = glCreateShader(GL_VERTEX_SHADER);
    char* vert_src = readShader(vertSrcDir);
    glShaderSource(program.vert_id, 1, (const char**)&vert_src, NULL);
    glCompileShader(program.vert_id);
    free(vert_src);

    /* Compiling Fragment Shader */
    program.frag_id = glCreateShader(GL_FRAGMENT_SHADER);
    char* frag_src = readShader(fragSrcDir);
    glShaderSource(program.frag_id, 1, (const char**)&frag_src, NULL);
    glCompileShader(program.frag_id);
    free(frag_src);

    /* Linking Shaders */
    program.id = glCreateProgram();
    glAttachShader(program.id, program.vert_id);
    glAttachShader(program.id, program.frag_id);
    glLinkProgram(program.id);

    /* Flagging the shaders for deletion once the shader program is destroyed */
    glDeleteShader(program.vert_id);
    glDeleteShader(program.frag_id);

    return program;
}