#pragma once
#include <stdio.h>
#include <malloc.h>
#include <glad/glad.h>

typedef struct shader {
	const char* vertex_shader;
	const char* fragment_shader;
	unsigned int id;
}shader;

void Shader(shader* new_shader);
unsigned int CompileShader(unsigned int type, const char* source);
unsigned int CreateShader(const char* vertex_shader, const char* fragments_shader);
char* ReadShader(const char* filepath);
void BindShader(unsigned int id);
void UnbindShader();
void FreeShader(shader* new_shader);
void DeleteShader(unsigned int id);