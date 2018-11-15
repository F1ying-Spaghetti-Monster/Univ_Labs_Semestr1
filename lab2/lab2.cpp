#include <iostream>
#include <GL/glut.h>
#include <vector>

using namespace std;

vector<int> Xcoordinate;
vector<int> Ycoordinate;
vector<int> radius;
vector<int> VelocityX;
vector<int> VelocityY;
// vector <int>* Xcoord = &Xcoordinate;
// vector <int>* Ycoord = &Ycoordinate;
// vector <int>* R = &radius;
// vector <int>* Vx = &VelocityX;
// vector <int>* Vy = &VelocityY;

int defaultRadius = 10;

void mouse_function(int button, int state, int x, int y)
{
    Xcoordinate.push_back(x);
    Ycoordinate.push_back(y);
    radius.push_back(defaultRadius);
    VelocityX.push_back(10);
    VelocityY.push_back(10);
}

void draw_a_circle(int x0, int y0, int r)
{
    int x = r - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (r << 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, (GLdouble) 1000, 0.0, (GLdouble) 1000 );
    glTranslatef(-0.5, -0.5, 0);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    while (x >= y)
    {
        glVertex2i(x0 + x, y0 + y);
        glVertex2i(x0 + y, y0 + x);
        glVertex2i(x0 - y, y0 + x);
        glVertex2i(x0 - x, y0 + y);
        glVertex2i(x0 - x, y0 - y);
        glVertex2i(x0 - y, y0 - x);
        glVertex2i(x0 + y, y0 - x);
        glVertex2i(x0 + x, y0 - y);

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (r << 1);
        }
    }
    glEnd();
    glFlush();
}

void display(void)
{
    // glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i++; i < Xcoordinate.size())
    {
        draw_a_circle(Xcoordinate[i], Ycoordinate[i], radius[i]);
    }

}

int main(int argc, char **argv)
{
    Xcoordinate.push_back(500);
    Ycoordinate.push_back(500);
    radius.push_back(100);
    cout << Xcoordinate[0] << " " << Ycoordinate[0] << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hopefully this works");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
