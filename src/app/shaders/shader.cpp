/* STDLIB */
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/* SOURCE */
#include "app/shaders/shader.h"

ShaderProgram::ShaderProgram(const std::string& vertex_path, const std::string& fragment_path)
{
    std::string vertex_code = read_file(vertex_path);
    std::string fragment_code = read_file(fragment_path);

    GLuint vertex = compile_shader(GL_VERTEX_SHADER, vertex_code);
    GLuint fragment = compile_shader(GL_FRAGMENT_SHADER, fragment_code);

    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(id);
}

void ShaderProgram::use()
{
    glUseProgram(id);
}

std::string ShaderProgram::read_file(const std::string& file_path)
{
    std::ifstream file(file_path);
    if (!file) {
        std::cerr << "ERROR: Cannot open file " << file_path << '\n';
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

unsigned int ShaderProgram::compile_shader(GLenum type, const std::string& source)
{
    GLuint shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
    return shader;
}