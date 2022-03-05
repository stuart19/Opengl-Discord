#version 330 core

layout(location = 0) in vec3 pos;

layout(location = 1) in vec3 vcolor_in;

//layout(location = 2) in vec2 vtex_coord_in;

out vec3 vcolor_out;
//out vec2 vtex_coord_out;

void main()
{
	gl_Position = vec4(pos, 1.0);

	vcolor_out = vcolor_in;

	//vtex_coord_out = vtex_coord_in;
}