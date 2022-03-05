#include "vao.h"

void Vao(vao* new_vao) {
	glGenVertexArrays(1, &(new_vao->id));
}

void DeleteVao(vao* new_vao) {
	glDeleteVertexArrays(1, &(new_vao->id));
}

void LinkAttribute(unsigned int layout, unsigned int num_of_components, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* offset) {
	glVertexAttribPointer(layout, num_of_components, type, normalized, stride, offset);
	glEnableVertexAttribArray(layout);
	//Bind vbo ?
}
void BindVao(vao* new_vao) {
	glBindVertexArray(new_vao->id);
}
void UnbindVao() {
	glBindVertexArray(0);
}