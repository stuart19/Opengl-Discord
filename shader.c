#include "shader.h"

void Shader(shader* new_shader) {
    new_shader->vertex_shader = ReadShader("vertex_shader.shader");
    new_shader->fragment_shader = ReadShader("fragment_shader.shader");

    new_shader->id = CreateShader(new_shader->vertex_shader, new_shader->fragment_shader);
}

unsigned int CompileShader(unsigned int type, const char* source) {
    unsigned int id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    int status;
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);

    if (status == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)_malloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        fprintf(stderr, "Failed to compile shader :\n %s\n", message);
        glDeleteShader(id);
        return 0;
    }

    return id;
}
unsigned int CreateShader(const char* vertex_shader, const char* fragment_shader) {
    unsigned int id = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex_shader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment_shader);

    glAttachShader(id, vs);
    glAttachShader(id, fs);
    glBindFragDataLocation(id, 0, "fragment_color_out");
    glLinkProgram(id);
    glValidateProgram(id);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return id;
}
char* ReadShader(const char* filepath) {
    FILE* file;
    size_t read_bytes = 0;

    file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Could not open shader file");
        return NULL;
    }
    fseek(file, 0L, SEEK_END);
    const size_t size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    char* buffer = (char*)malloc(size + 1);
    if (buffer == NULL) {
        printf("Could not allocate memory");
        return NULL;
    }
    read_bytes = fread(buffer, sizeof(char), size, file);
    buffer[read_bytes] = '\0';
    fclose(file);
    return buffer;
}
void BindShader(unsigned int id) {
    glUseProgram(id);
}
void UnbindShader() {
    glUseProgram(0);
}
void FreeShader(shader* new_shader) {
    free(new_shader->vertex_shader);
    free(new_shader->fragment_shader);
}
void DeleteShader(unsigned int id) {
    glDeleteProgram(id);
}