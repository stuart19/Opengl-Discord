#pragma once
#include <stdio.h>
#include <glad/glad.h>

typedef struct texture {
	unsigned int id;
	GLenum slot;
	GLenum target;
	GLenum filter;
	GLenum wrapping;
	char* image;
	int width_img;
	int height_img;
	int num_col_ch;
	int format;
}texture;

void Texture(texture* new_texture, GLenum slot, GLenum target, GLenum filter, GLenum wrapping, char* image, int format);
void DeleteTexture(texture* new_texture);
void TextureData(texture* new_texture);
void BindTexture(texture* new_texture);
void UnbindTexture(texture* new_texture);
void TextureParameter(texture* new_texture);
unsigned char* LoadImage(texture* new_texture, const char* source);
void LoadTexture(texture* new_texture);