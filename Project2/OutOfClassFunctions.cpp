#include "Structs.h"
#include"OutOfClassFunctions.h"
void InitializeBuffers(UINT* VBO, UINT* VAO, UINT* ibo )
{
    glGenVertexArrays(1, VAO);
    glGenBuffers(1, VBO);
    glGenBuffers(1, ibo);
    glBindVertexArray(*VAO);
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (const void*)12);
    glEnableVertexArrayAttrib(*VBO,1);
    glEnableVertexAttribArray(0);
}
void timer(bool* arg,bool* arg2)
{
    while (true)
    {
        sleep_for(0.01s);
        *arg = true;
        for(int i=0;i<11;i++)
        {
            arg2[i] = true;
        }
    }
}
unsigned int createshade(unsigned int type, const string& shader)
{
    unsigned int Shader = glCreateShader(type);
    const char* src = shader.c_str();
    glShaderSource(Shader, 1, &src, NULL);
    glCompileShader(Shader);
    int DidSuccess;
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &DidSuccess);
    if (!DidSuccess)
    {
        int length;
        glGetShaderiv(Shader, GL_INFO_LOG_LENGTH, &length);
        char* infoLog = (char*)calloc(length, sizeof(char));
        glGetShaderInfoLog(Shader, 512, NULL, infoLog);
        std::cout << "ERROR" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "COMPILATION_FAILED\n" << infoLog << std::endl;
        glDeleteShader(Shader);
        free(infoLog);
        return 0;
    }
    return Shader;
}
DPOINT GetScreenResolution()
{
    POINT inintialCursorPos,MaxcursorPos;
    GetCursorPos(&inintialCursorPos);
    SetCursorPos(100000, 100000);
    GetCursorPos(&MaxcursorPos);
    SetCursorPos(inintialCursorPos.x,inintialCursorPos.y);
    return { double(MaxcursorPos.x), double(MaxcursorPos.y)};
}
string read(string name)
{

    fstream file;
    file.open(name, fstream::out | fstream::in | fstream::app);
    if (!file.is_open())
    {
        cout << "couldnt open";
    }
    string lineoutput, line;
    while (getline(file, lineoutput))
    {
        line += lineoutput + "\n";
    }
    file.close();
    return line;
}
void GLAPIENTRY MessageCallBack(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    cout << "OpenGL Error:"<<message<<endl;
}
unsigned int* add(unsigned int a[], int size1, unsigned int b[], int size2)
{
    unsigned int* arr = new unsigned int[size1 + size2];
    for (int i = 0; i < size1; i++)
    {
        arr[i] = a[i];
    }
    for (int i = 0; i < size2; i++)
    {
        arr[i + size1] = b[i] + 8 * (int(i / 36) + int(size1 / 36));
    }
    return arr;
}