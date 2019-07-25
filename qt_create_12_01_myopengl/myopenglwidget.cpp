#include "myopenglwidget.h"
#include <QOpenGLShaderProgram>

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

void MyOpenGLWidget::initializeGL()
{
    // 为当前环境初始化OpenGL函数
    initializeOpenGLFunctions();
    // 创建顶点着色器
    QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    const char *vsrc =
            "void main() {                             \n"
            "   gl_Position = vec4(0.0, 0.0, 0.0, 1.0);\n"
            "}                                         \n";
    vshader->compileSourceCode(vsrc);
    // 创建片段着色器
    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    const char *fsrc =
            "void main() {                              \n"
            "   gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
            "}                                          \n";
    fshader->compileSourceCode(fsrc);
     // 创建着色器程序
    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);
    program->link();
    program->bind();
}
/*
    这里首先调用 QOpenGLFunctions::initializeOpenGLFunctions()对 OpenGL函数进行了初始化,
    这样 QOpenGLFunctions中的函数只能在当前环境中使用。然后进行了看色器的相关设置。
    使用QOpenGlLShader创建 了一顶点着色器 和一片段着色器，
    并使用compileSourceCode()函数为着色器设置了源码并进行了编译。
    下面创建了着色器程序QOpenGLShaderProgram对象，
    使用addShader()将前面已经编译好的着色器添加进来，
    然后调用link(）函数将所有加入到程序中的着色器链接到一起，
    最后调用bind（）函数将该着色器程序绑定到当前OpenGL环境中。
*/
void MyOpenGLWidget::paintGL()
{
    // 绘制
    glDrawArrays(GL_POINTS, 0, 1);
}

void MyOpenGLWidget::resizeGL(int /*width*/, int /*height*/)
{

}
