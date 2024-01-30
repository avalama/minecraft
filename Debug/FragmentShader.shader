#version 450 core

out vec4 Color;

in vec3 v_Color;

void main()
{
  Color = vec4(v_Color,1.0);
};