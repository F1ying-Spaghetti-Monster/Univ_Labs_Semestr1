#include <GL/glut.h>

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, (GLdouble) 1000, 0.0, (GLdouble) 1000 );
    glTranslatef(-0.5, -0.5, 0);
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(300, 300);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(300, 500);

        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(500, 500);
        
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(500,300);
        
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world :D");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}