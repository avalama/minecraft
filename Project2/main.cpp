#include "MainHeader.h"
static unsigned int createprog(const string& vertex, const string& fragment)
{
    unsigned int fShader = createshade(GL_FRAGMENT_SHADER, fragment.c_str());
    unsigned int vShader = createshade(GL_VERTEX_SHADER, vertex.c_str());
    unsigned int prog = glCreateProgram();
    glAttachShader(prog, vShader);
    glAttachShader(prog, fShader);
    glLinkProgram(prog);
    glValidateProgram(prog);
    glDeleteShader(fShader);
    glDeleteShader(vShader);
    return prog;
}
unsigned int* add(unsigned int a[],unsigned int b[],int size)
{
    unsigned int* arr=new unsigned int[size];
    for (int i = 0; i < size/2; i++)
    {
        arr[i] = a[i];
    }
    for (int i = 0; i < size / 2; i++)
    {
        arr[i + size / 2] = b[i]-8+size/4.5;
    }
    return arr;
}
int main()
{
    unsigned int VBO, VAO, ibo;
    bool MoveRights = true, cirrights[11] = { false,false,false,false,false,false,false,false,false,false,false },IsMouseActivated = false;
    cube cube1({ 0,0,0 }, 0.2f,1), cube2({ 0.8,0.8,0.4 },0.2f,2);
    camera MyCamera(cube1.CubeShapeLength);
    floatarray Vertecies;
    thread movetimer(timer, &MoveRights,cirrights);
    movetimer.detach();
	glfwInit();
	GLFWwindow* MainWindow = glfwCreateWindow(800, 800, "LearnOpenGL", nullptr, nullptr);
    if (nullptr == MainWindow)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(MainWindow);
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    unsigned int shader = createprog(read("VertexShader.shader"), read("FragmentShader.shader"));
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallBack, 0);
    glUseProgram(shader);
    InitializeBuffers(&VBO, &VAO, &ibo);
    glBufferData(GL_ARRAY_BUFFER, MyCamera.ArrayToBuffer.length*sizeof(float), cube1.CubeShape, GL_DYNAMIC_DRAW);
    unsigned int* ElementToBuffer = add(cube1.element, cube2.element, cube1.ElementLength * 2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube1.ElementLength*sizeof(unsigned int)*2,ElementToBuffer, GL_DYNAMIC_DRAW);
    delete(ElementToBuffer);
    while (!glfwWindowShouldClose(MainWindow))
    {
        MyCamera.getinput(cirrights);
        if (MoveRights)
        {
            MoveRights = false;
            cube1.Move();
        }
        if (IsMouseActivated)
        {
            MyCamera.GetMouseChanges();
        }
        else
        {
            if (GetAsyncKeyState(9))
            {
                IsMouseActivated = true;
                GetCursorPos(&MyCamera.LongCurs);
                MyCamera.lastCursorPos.x = MyCamera.LongCurs.x;
                MyCamera.lastCursorPos.y = MyCamera.LongCurs.y;
            }
        }
        Vertecies.id = 4;
        Vertecies = MyCamera.RotateCube(&cube2).add(MyCamera.RotateCube(&cube1));
        Vertecies.exist = true;
        glBufferData(GL_ARRAY_BUFFER, Vertecies.length * sizeof(float), Vertecies.arraystart, GL_DYNAMIC_DRAW);
        glClearColor(0.4, 0.3, 0.5, 1.0);
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, cube1.ElementLength*2, GL_UNSIGNED_INT,nullptr);
        glfwSwapBuffers(MainWindow);
    }
    glfwTerminate();
    glDeleteProgram(shader);
    return 0;
}