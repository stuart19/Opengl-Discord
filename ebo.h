#pragma once
#include <stdio.h>
#include <glad/glad.h>

typedef struct ebo {
	unsigned int id;
	unsigned int size;
	unsigned int* data;
}ebo;

void Ebo(ebo* new_ebo, unsigned int size, unsigned int* data);
void DeleteEbo(ebo* new_ebo);
void EboData(ebo* new_ebo, GLenum usage);
void BindEbo(ebo* new_ebo);
void UnbindEbo();
