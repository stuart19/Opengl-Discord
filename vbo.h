#pragma once

typedef struct vbo {
	unsigned int id;
	GLsizeiptr size;
	float* data;
}vbo;


void Vbo(vbo* new_vbo, GLsizeiptr size, float* data);
void DeleteVbo(vbo* new_vbo);
void VboData(vbo* new_vbo, GLenum usage);
void BindVbo(vbo* new_vbo);
void UnbindVbo();