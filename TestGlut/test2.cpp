#include <stdio.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#ifndef var
#define var __auto_type
#endif

static const GLfloat sRectVertices[] = {
    // top left
    -0.4f, 0.4f,

    // bottom left
    -0.4f, -0.4f,

    // top right
    0.4f, 0.4f,

    // bottom right
    0.4f, -0.4f
};

static const GLfloat sTriangleVertices[] = {
    // top center
    0.0f, 0.4f,

    // bottom left
    -0.4f, -0.4f,

    // bottom right
    0.4f, -0.4f
};

static const GLfloat sColors[] = {
    // red
    1.0f, 0.0f, 0.0f, 1.0f,

    // green
    0.0f, 1.0f, 0.0f, 1.0f,

    // blue
    0.0f, 0.0f, 1.0f, 1.0f,

    // white
    1.0f, 1.0f, 1.0f, 1.0f
};


static void RenderHandler(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw rectangle
    glVertexPointer(2, GL_FLOAT, 0, sRectVertices);
    glColorPointer(4, GL_FLOAT, 0, sColors);

    glLoadIdentity();
    glTranslatef(-0.5f, 0.0f, -2.0f);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    // Draw triangle
    glVertexPointer(2, GL_FLOAT, 0, sTriangleVertices);
    glColorPointer(4, GL_FLOAT, 0, sColors);

    glLoadIdentity();
    glTranslatef(0.5f, 0.0f, -2.1f);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glFlush();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("OpenGL GLUT Demo");

    glutDisplayFunc(RenderHandler);

    auto  vendor = (const char*)glGetString(GL_VENDOR);
    auto  renderer = (const char*)glGetString(GL_RENDERER);
    auto  version = (const char*)glGetString(GL_VERSION);
    printf("The vendor is: %s\n", vendor);
    printf("The renderer is: %s\n", renderer);
    printf("The GL version is: %s\n", version);

    glViewport(0, 0, 480, 480);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_SMOOTH);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    glEnable(GL_CULL_FACE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 3.0f);

    glMatrixMode(GL_MODELVIEW);

    glutMainLoop();
}