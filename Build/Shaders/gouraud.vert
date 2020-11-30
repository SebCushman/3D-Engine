#version 430 core

layout (location = 0) in vec3 vs_position;
layout (location = 1) in vec3 vs_normal;

out vec3 fs_color;

struct Material{
	vec3 ambient;
	vec3 diffuse;
};

uniform Material material;

struct Light{
	vec4 position;
	vec3 ambient;
	vec3 diffuse;
};

uniform Light light;

uniform mat4 transform;

void main()
{
	vec3 ambient = material.ambient * light.ambient;

	fs_color = ambient;
	gl_Position = transform * vec4(vs_position, 1.0);
}