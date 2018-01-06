#ifndef OGLPYRAMID_H
#define OGLPYRAMID_H

#include <QGLWidget>
#include <QMouseEvent>

class OGLPyramid : public QGLWidget
{
    //Q_OBJECT
private:
    GLuint m_nPyra;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint m_ptPosition;
protected:
    virtual void initializeGL();
    virtual void resizeGL(int nWidth, int nHeight);
    virtual void paintGL();
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);
    GLuint createPyra(GLfloat fsize = 1.0f);

public:
    OGLPyramid(QGLWidget *parent = 0);
    ~OGLPyramid();
};

#endif // OGLPYRAMID_H
