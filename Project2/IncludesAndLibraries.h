#pragma once
#define GLEW_STATIC 
#define _USE_MATH_DEFINES
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<thread>
#include<chrono>
#include<cstdlib>
#include<fstream>
#include<string>
#include"opengl/dependencis/glew/include/GL/glew.h"
#pragma comment(lib,"opengl/dependencis/glfw64/lib-vc2022/glfw3.lib")
#pragma comment(lib,"opengl/dependencis/glew/lib/Release/x64/glew32s.lib")
#pragma comment(lib,"opengl32.lib")
#include"opengl/dependencis/glfw/include/GLFW/glfw3.h"
using namespace std;
using std::this_thread::sleep_for;