#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb/stb_image.h"
#include <cglm/cglm.h> 

#include "vbo.h"
#include "ebo.h"
#include "vao.h"
#include "texture.h"
#include "shader.h"

const int width = 800;
const int height = 800;

int main(void)
{
    GLFWwindow* window;
 
    if (!glfwInit()) {
        fprintf(stderr, "Could not initialize GLFW !\n");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGL()) {
        fprintf(stderr, "Could not initialize GLAD !\n");
        return -1;
    }

    glViewport(0, 0, width, height);

    float vertices[] = { 
     0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
    -0.5f,  0.5f, 0.0f,  0.5f, 0.5f, 0.5f,   0.0f, 1.0f
    };
    unsigned int indices[6] = {
     0, 1, 3,
     1, 2, 3
    };
    
    vao vao1;
    Vao(&vao1);
    BindVao(&vao1);

    vbo vbo1;
    Vbo(&vbo1, ((4 * 8) * sizeof(float)), vertices);
    VboData(&vbo1, GL_STATIC_DRAW);

    ebo ebo1;
    Ebo(&ebo1, 6 * sizeof(unsigned int), indices);
    EboData(&ebo1, GL_STATIC_DRAW);

    shader shader1;
    Shader(&shader1);
    BindShader(shader1.id);

    LinkAttribute(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    LinkAttribute(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    LinkAttribute(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    texture tex1;
    unsigned char* image = LoadImage(&tex1, "Resources\\pop_cat.png");
    Texture(&tex1, GL_TEXTURE0, GL_TEXTURE_2D, GL_NEAREST, GL_REPEAT, NULL, GL_RGBA);
    TextureData(&tex1); 
    TextureParameter(&tex1);
    LoadTexture(&tex1);

    stbi_image_free((void*)image);

    int tex0_uni = glGetUniformLocation(shader1.id, "tex0");
    glUniform1i(tex0_uni, 0);

    UnbindVbo();
    UnbindVao();
    UnbindShader();
    UnbindTexture(&tex1);

    while (!glfwWindowShouldClose(window)){
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        BindShader(shader1.id);
        BindTexture(&tex1);
        BindVao(&vao1);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    DeleteVbo(&vbo1);
    DeleteEbo(&ebo1);
    DeleteVao(&vao1);
    DeleteTexture(&tex1);
    DeleteShader(shader1.id);
    FreeShader(&shader1);

    glfwTerminate();
    return 0;
}