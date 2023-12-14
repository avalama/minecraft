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
unsigned int* add(unsigned int a[],int size1,unsigned int b[],int size2)
{
    unsigned int* arr=new unsigned int[size1+size2];
    for (int i = 0; i < size1; i++)
    {
        arr[i] = a[i];
    }
    for (int i = 0; i < size2; i++)
    {
        arr[i + size1] = b[i]+8*(int(i/36)+int(size1/36));
    }
    return arr;
}
int main()
{
    srand(time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) //only way to get ACTUAL random number
        * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL)
        * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL));
    unsigned int VBO, VAO, ibo;
    bool MoveRights = true, cirrights[11] = { false,false,false,false,false,false,false,false,false,false,false },IsMouseActivated = false;
    cube cube1({ 0,0,0 }, 0.1f,1), cube2({ 0.8,0.8,0.4 },0.1f,2), cube3({ 0.8,0.8,0 }, 0.1f,3);
    chunk chonk{1};
    camera MyCamera;
    floatarray Vertecies=chonk.renderbuffer(MyCamera);
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
    glBufferData(GL_ARRAY_BUFFER, Vertecies.length * sizeof(float), cube1.CubeShape, GL_DYNAMIC_DRAW);
    unsigned int* ElementToBuffer = add(add(cube1.element,cube1.ElementLength, cube2.element, cube1.ElementLength ),cube1.ElementLength*2, cube3.element, cube1.ElementLength);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube1.ElementLength*sizeof(unsigned int)*3,ElementToBuffer, GL_DYNAMIC_DRAW);
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
        Vertecies = MyCamera.RotateCube(&cube1).add(MyCamera.RotateCube(&cube2).add(MyCamera.RotateCube(&cube3)));
        Vertecies.exist = true;
        glBufferData(GL_ARRAY_BUFFER, Vertecies.length * sizeof(float), Vertecies.arraystart, GL_DYNAMIC_DRAW);
        if (cube1.id == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,2 });
            for (int i = 0; i < cube1.CubeShapeLength; i += cube1.VertexLength)
            {
                cout << Vertecies.arraystart[i ] << "  ,  " << Vertecies.arraystart[i + 1 ] << "  ,  " << Vertecies.arraystart[i + 2 ] << "  ,  " << Vertecies.arraystart[i + 3 ] << "  ,  " << Vertecies.arraystart[i + 4 ] << "  ,  " << Vertecies.arraystart[i + 5 ] << "                          " << endl;
            }
        }

        if (cube1.id == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,14 });
            for (int i = 0; i < cube1.CubeShapeLength; i += cube1.VertexLength)
            {
                cout << cube1.CubeShape[i] << "  ,  " << cube1.CubeShape[i + 1] << "  ,  " << cube1.CubeShape[i + 2 ] << "  ,  " << cube1.CubeShape[i + 3 ] << "  ,  " << cube1.CubeShape[i + 4 ] << "  ,  " << cube1.CubeShape[i + 5 ] << "                          " << endl;
            }
        }
        glClearColor(0.4, 0.3, 0.5, 1.0);
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, cube1.ElementLength*3, GL_UNSIGNED_INT,nullptr);
        glfwSwapBuffers(MainWindow);
    }
    glfwTerminate();
    glDeleteProgram(shader);
    return 0;
}