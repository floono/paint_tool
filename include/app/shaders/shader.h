#pragma once

/* STD */
#include <string>

/* GLAD */
#include <glad/glad.h>

class ShaderProgram
{
    private:
        static std::string read_file(const std::string& file_path);
        static unsigned int compile_shader(GLenum type, const std::string& source);

    public:
        unsigned int id;

        ShaderProgram(const std::string& vertex_path, const std::string& fragment_path);
        ~ShaderProgram();
        void use();
};