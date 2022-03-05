#pragma once
#include "ebo.h"

void Ebo(ebo* new_ebo, unsigned int size, unsigned int* data) {
	new_ebo->size = size;
	new_ebo->data = data;
	glGenBuffers(1, &(new_ebo->id));
}

void DeleteEbo(ebo* new_ebo) {
	glDeleteBuffers(1, &(new_ebo->id));
}

void EboData(ebo* new_ebo, GLenum usage) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, new_ebo->id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, new_ebo->size, new_ebo->data, usage);
}

void BindEbo(ebo* new_ebo) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, new_ebo->id); 
}
void UnbindEbo() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}