#pragma once
#include <stdio.h>
#include <glad/glad.h>

typedef struct vao {
	unsigned int id; // add stride to the struct ?
}vao;

void Vao(vao* new_vao);
void DeleteVao(vao* new_vao);
void LinkAttribute(unsigned int layout, unsigned int num_of_components, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* offset);
void BindVao(vao* new_vao);
void UnbindVao();