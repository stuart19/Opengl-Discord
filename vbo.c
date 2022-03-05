#include <stdio.h>
#include <glad/glad.h>
#include "vbo.h"

void Vbo(vbo* new_vbo, GLsizeiptr size, float* data) {
	new_vbo->size = size;
	new_vbo->data = data;
	glGenBuffers(1, &(new_vbo->id));
}	

void DeleteVbo(vbo* new_vbo) {
	glDeleteBuffers(1, &(new_vbo->id));
}

void VboData(vbo* new_vbo, GLenum usage) {
	glBindBuffer(GL_ARRAY_BUFFER, new_vbo->id);
	glBufferData(GL_ARRAY_BUFFER, new_vbo->size, new_vbo->data, usage); 
}

void BindVbo(vbo* new_vbo) {
	glBindBuffer(GL_ARRAY_BUFFER, new_vbo->id);
}

void UnbindVbo() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
