#version 450 core

layout (location = 0) in vec3 position;

layout (location = 1) in vec3 a_Color;

out vec3 v_Color;

void main()
{
   v_Color = a_Color;
   gl_Position = vec4(position,1.0);
};