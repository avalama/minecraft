#pragma once
#include"Structs.h"
#include"FloatArray.h"
//vbo,vao,ibo
void InitializeBuffers(UINT*, UINT*, UINT*);
void timer(bool*, bool*);
unsigned int createshade(unsigned int type, const string& shader);
string read(string);
DPOINT GetScreenResolution();
void GLAPIENTRY MessageCallBack(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
unsigned int* add(unsigned int* a, int size1, unsigned int* b, int size2);
unsigned int* addn(unsigned int* a, int size1, unsigned int* b, int size2);
void debugF(floatarray);