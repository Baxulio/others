#include "oglpyramid.h"

OGLPyramid::OGLPyramid(QGLWidget *parent)
    : QGLWidget(parent),m_xRotate(0),m_yRotate(0)
{
}
void OGLPyramid::initializeGL()
{
    qglClearColor(Qt::green);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    m_nPyra = createPyra(1.2f);
}

void OGLPyramid::resizeGL(int nWidth, int nHeight)
{
    glViewport(0,0,GLint(nWidth),GLint(nHeight));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0, -1.0, 1.0, 1.0, 10.0);
}

void OGLPyramid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);

    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);

    glCallList(m_nPyra);
}

void OGLPyramid::mousePressEvent(QMouseEvent *pe)
{
    m_ptPosition = pe->pos();
}

void OGLPyramid::mouseMoveEvent(QMouseEvent *pe)
{
    m_xRotate += 180*(GLfloat)(pe->y()-m_ptPosition.y())/height();
    m_xRotate += 180*(GLfloat)(pe->x()-m_ptPosition.x())/width();
    updateGL();

    m_ptPosition = pe->pos();
}

GLuint OGLPyramid::createPyra(GLfloat fsize)
{
    GLuint n= glGenLists(1);
    glNewList(n,GL_COMPILE);
        glBegin(GL_TRIANGLE_FAN);
            qglColor(Qt::red);
            glVertex3f(0.0, fsize, 0.0);
            glVertex3f(-fsize, -fsize, fsize);
            glVertex3f(fsize, -fsize, fsize);

            qglColor(Qt::yellow);
            glVertex3f(fsize, -fsize, -fsize);

            qglColor(Qt::blue);
            glVertex3f(-fsize, -fsize, -fsize);

            qglColor(Qt::white);
            glVertex3f(-fsize, -fsize, fsize);
        glEnd();

        glBegin(GL_QUADS);
            qglColor(Qt::black);
            glVertex3f(-fsize, -fsize, fsize);
            glVertex3f(fsize, -fsize, fsize);
            glVertex3f(fsize, -fsize, -fsize);
            glVertex3f(-fsize, -fsize, -fsize);
        glEnd();
    glEndList();

    return n;
}

OGLPyramid::~OGLPyramid()
{

}
