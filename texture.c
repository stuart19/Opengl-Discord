#pragma once
#include "texture.h"

void Texture(texture* new_texture, GLenum slot, GLenum target, GLenum filter, GLenum wrapping, char* image, int format) {
	new_texture->slot = slot;
	new_texture->target = target;
	new_texture->filter = filter;
	new_texture->wrapping = wrapping;
	new_texture->image = image;
	new_texture->format = format;
	
	glGenTextures(1, &(new_texture->id));
}

void DeleteTexture(texture* new_texture) {
	glDeleteTextures(1, &(new_texture->id));
}

void TextureData(texture* new_texture) {
	glActiveTexture(new_texture->slot);
	glBindTexture(new_texture->target, &(new_texture->id));
}

void BindTexture(texture* new_texture) {
	glBindTexture(new_texture->target, &(new_texture->id));
}

void UnbindTexture(texture* new_texture) {
	glBindTexture(new_texture->target, 0);
}

void TextureParameter(texture* new_texture) {
	glTexParameteri(new_texture->target, GL_TEXTURE_MIN_FILTER, new_texture->filter);
	glTexParameteri(new_texture->target, GL_TEXTURE_MAG_FILTER, new_texture->filter);

	glTexParameteri(new_texture->target, GL_TEXTURE_WRAP_S, new_texture->wrapping);
	glTexParameteri(new_texture->target, GL_TEXTURE_WRAP_T, new_texture->wrapping);
}

unsigned char* LoadImage(texture* new_texture, const char* source) {
	stbi_set_flip_vertically_on_load(1);
	unsigned char* bytes_read = stbi_load(source, &(new_texture->width_img), &(new_texture->height_img), &(new_texture->num_col_ch), 0);
	if (bytes_read == NULL) {
		fprintf(stderr, "Could not load image");
		return NULL;
	}
		
	return bytes_read;
}
void LoadTexture(texture* new_texture) {
	glTexImage2D(new_texture->target, 0, new_texture->format, new_texture->width_img, new_texture->height_img, 0, new_texture->format, GL_UNSIGNED_BYTE, new_texture->image);
	glGenerateMipmap(new_texture->target);
}