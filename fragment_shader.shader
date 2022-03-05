#version 330 core

out vec4 fcolor_out;

in vec3 vcolor_out;

//in vec2 vtex_coord_out;

//uniform sampler2D tex0;


void main()
{
	fcolor_out = vec4(vcolor_out, 1.0f);//texture(tex0, vtex_coord_out);
}