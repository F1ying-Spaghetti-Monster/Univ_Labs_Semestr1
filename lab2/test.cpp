#include <iostream>
#include <GL/glut.h>
#include <vector>
#include <thread>
#include <chrono>
#include <math.h>


using namespace std;

vector<int> Xcoordinate;
vector<int> Ycoordinate;
vector<int> radius;
vector<int> Vx;
vector<int> Vy;
vector<int> tracer_line_x;
vector<int> tracer_line_y;

int program_status = 0;  // 0 for allowing to edit objects, 1 for movement

int window_width = 1000;
int window_hight = 1000;

int defaultRadius = 50;
int selectedCircleIndex = -1;

double distance_between_2_points (int x1, int y1, int x2, int y2){
    return sqrt( (double) (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void keyboard (unsigned char key,int x,int y){
    if ( program_status == 0){
        switch (key){
            case 'a':
                if (x > 0 && x < window_width && window_hight - y > 0 && y > 0){     
                Xcoordinate.push_back(x);
                Ycoordinate.push_back(window_hight-y);
                radius.push_back(defaultRadius);
                Vx.push_back(50);
                Vy.push_back(50);
                cout << x << " " << y  << endl;
                }
                break;
            case 'm': 
                if (selectedCircleIndex != -1)
                if (distance_between_2_points(x,window_hight-y,Xcoordinate[selectedCircleIndex], Ycoordinate[selectedCircleIndex]) < radius[selectedCircleIndex]){
                    Xcoordinate[selectedCircleIndex] = x;
                    Ycoordinate[selectedCircleIndex] = window_hight-y;
                }
                break;
            case 'p': 
                program_status = 1;
                break;
            case'w':
                if (selectedCircleIndex != -1){
                    radius[selectedCircleIndex] += 10;
                }
                break;
            case 's':
                if (selectedCircleIndex != -1 && radius[selectedCircleIndex] > 10){
                    radius[selectedCircleIndex] -= 10;
                }    
                break;
            case '\e': cout << "THERE IS NO ESCAPE"<< endl;
                break;
            case  127: 
            case '\b':
                if (selectedCircleIndex != -1 && Xcoordinate.size()>1){
                Xcoordinate.erase(Xcoordinate.begin() + selectedCircleIndex);
                Ycoordinate.erase(Ycoordinate.begin() + selectedCircleIndex);
                Vx.erase(Vx.begin() + selectedCircleIndex);
                Vy.erase(Vy.begin() + selectedCircleIndex);
                radius.erase(radius.begin() + selectedCircleIndex);
                selectedCircleIndex = -1;
                }
                break;
            default:
                break;    
        }
    }
    
    else if (program_status == 1){
        switch (key){
            case 'p': 
                program_status = 0;
                break;
            case '\e': cout << "THERE IS NO ESCAPE!!!"<< endl;
                break;    
            default:
                break;  
        }
    }
    

}



void mouse (int button, int status, int x, int y){
    if (program_status == 0) {
        if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN){
        for (int i = 0; i < Xcoordinate.size(); i++){
            if (distance_between_2_points(x, window_hight - y, Xcoordinate[i], Ycoordinate[i]) <= radius[i]){
                cout << "in circle" << endl;
                selectedCircleIndex = i;
                break;
            }
            else {
                selectedCircleIndex = -1;
            }

        }
        tracer_line_x.erase(tracer_line_x.begin(), tracer_line_x.end());
        tracer_line_y.erase(tracer_line_y.begin(), tracer_line_y.end());
        }

    }
}

void physics_switch_speed (int i, int j){
                    cout << "collision" << endl;
                    cout << "old V: " << Vx[i] << " " << Vy[i] << " "<<Vx[j] << " " << Vy[j] << endl;

                        if (Ycoordinate[i] > Ycoordinate[j]){
                            int a = Vx[i];
                            Vx[i] = -Vy[i];
                            Vy[i] = a;
                            a = Vx[j];
                            Vx[j] = -Vy[j];
                            Vy[j] = a;
                        }
                        double angle1 = ( Xcoordinate[j] - Xcoordinate[i] )/ (radius[i] + radius[j]) ;
                        angle1 = acos(angle1);
                        double angle2 = Vx[i] / distance_between_2_points(0, 0, Vx[i], Vy[i]);

                        
                        Vy[i] > 0 ? angle2 = acos(angle2) : angle2 = 2 * M_PI - acos(angle2);
                        double angle3;
                        angle2 > angle1 ? angle3 = angle2 - angle1 : angle3 = angle1 - angle2;

                        double proection1 = distance_between_2_points(0, 0, Vx[i], Vy[i]) * cos(angle3);

                        double angle4 = Vx[j] / distance_between_2_points(0, 0, Vx[j], Vy[j]);
                        Vy[j] > 0 ? angle4 = acos(angle4) : angle4 = 2 * M_PI - acos(angle4);
                        double angle5;
                        angle4 > angle1 ? angle5 = angle4 - angle1 : angle5 = angle1 - angle4;
                        cout << "angle1: " << angle1 * 180 /M_PI<< " angle2: " << angle2* 180 /M_PI << " angle4: " << angle4 * 180 /M_PI<< " angle5: " << angle5* 180 /M_PI << endl;
                        double proection2 = distance_between_2_points(0, 0, Vx[j], Vy[j]) * cos(angle5);

                        double newVxi = proection2 *cos(angle1) + distance_between_2_points(0, 0, Vx[i], Vy[i]) * sin (angle3) * cos(angle1 + M_PI/2);
                        double newVyi = proection2 *sin(angle1) + distance_between_2_points(0, 0, Vx[i], Vy[i]) * sin (angle3) * sin(angle1 + M_PI/2);
                        double newVxj = proection1 *cos(angle1) + distance_between_2_points(0, 0, Vx[j], Vy[j]) * sin (angle5) * cos(angle1 + M_PI/2);
                        double newVyj = proection1 *sin(angle1) + distance_between_2_points(0, 0, Vx[j], Vy[j]) * sin (angle5) * sin(angle1 + M_PI/2);
                        
                        
                        double ratio = (radius[i]/radius[j]);       //* (radius[i]/radius[j]) *(radius[i]/radius[j])
                        if (Ycoordinate[i] > Ycoordinate[j]){
                        Vx[i] = newVyi / ratio;
                        Vy[i] = - newVxi / ratio;
                        Vx[j] = ratio * newVyj;
                        Vy[j] = - ratio * newVxj;
                        }
                        else {
                        Vx[i] = newVxi;
                        Vy[i] = newVyi;
                        Vx[j] = newVxj;
                        Vy[j] = newVyj;
                        }
        
                        cout << "new V: " << Vx[i] << " " << Vy[i] << " "<<Vx[j] << " " << Vy[j] << endl;
                    
}

void check_if_out_of_bounds (int i){
        if (Xcoordinate[i] + radius[i] >= window_width){
        Xcoordinate[i] = 2*window_width - Xcoordinate[i] - 2 * radius[i];
        Vx[i] = -Vx[i];
    }
        if (Xcoordinate[i] - radius[i]<= 0){
        Xcoordinate[i] = - Xcoordinate[i] + 2* radius[i];
        Vx[i] = -Vx[i];
    }
    if (Ycoordinate[i] + radius[i]>= window_hight){
        Ycoordinate[i] =  2*window_hight - Ycoordinate[i] - 2 * radius[i];
        Vy[i] = -Vy[i];
    }
    if (Ycoordinate[i] - radius[i] <= 0){
        Ycoordinate[i] = - Ycoordinate[i] + 2* radius[i];
        Vy[i] = - Vy[i];
    }
}


void check_if_collision (void) {
    for ( int i = 0; i < Xcoordinate.size() -1; i++){
        for (int j = i+1; j < Xcoordinate.size(); j++){
                if ( distance_between_2_points(Xcoordinate[i] + 0.2*Vx[i], Ycoordinate[i] + 0.2 * Vy[i], Xcoordinate[j] + 0.2 * Vx[j], Ycoordinate[j] + 0.2 * Vy[i] ) <= radius[i] + radius[j]){  
                    if (Xcoordinate[j] >= Xcoordinate[i] )
                        physics_switch_speed (i, j);                    
                    else 
                        physics_switch_speed(j,i);                    
                    }
                }
        } 
    }



void drawingCircles (void){

    glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
    // this_thread::sleep_for(chrono::milliseconds(50));
    for (int i=0; i<Xcoordinate.size(); i++){

    
    check_if_out_of_bounds(i);

    if (radius[i] == 1){
        glColor3f(1, 1, 1);
        glVertex2i(Xcoordinate[i], Ycoordinate[i]);
    }

    else {
    int x = radius[i] -1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius[i] << 1);

    while (x>=y)
    {   

        glColor3f(1, 1, 1);
        //     if (i == selectedCircleIndex) {
        //         glColor3f(0, 0, 1);
        //         glBegin(GL_LINE_STRIP);
        //         glVertex2i(Xcoordinate[i], Ycoordinate[i]);
        //         glVertex2i(Xcoordinate[i] + Vx[i], Ycoordinate[i] + Vy[i]);
        //         glEnd();
        //         if (program_status == 1){
        //         tracer_line_x.push_back(Xcoordinate[i]);
        //         tracer_line_y.push_back(Ycoordinate[i]);
        //         }
        //         glBegin(GL_LINE_STRIP);
        //         glColor3f(1 , 1, 1);
        //         for (int k = 0; k < tracer_line_x.size(); k++){
        //             glVertex2i(tracer_line_x[k], tracer_line_y[k]);
        //         }
        //         glEnd();
        // glColor3f(1, 1, 0);
        // }
        
        glVertex2i(Xcoordinate[i] + x, Ycoordinate[i] + y);
        glVertex2i(Xcoordinate[i] + y, Ycoordinate[i] + x);
        glVertex2i(Xcoordinate[i] - y, Ycoordinate[i] + x);
        glVertex2i(Xcoordinate[i] - x, Ycoordinate[i] + y);
        glVertex2i(Xcoordinate[i] - x, Ycoordinate[i] - y);
        glVertex2i(Xcoordinate[i] - y, Ycoordinate[i] - x);
        glVertex2i(Xcoordinate[i] + y, Ycoordinate[i] - x);
        glVertex2i(Xcoordinate[i] + x, Ycoordinate[i] - y);
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
            err += dx - (radius[i] << 1);
        }
    }
    }

    if (program_status == 1){
    Xcoordinate[i] += 0.2 * Vx[i];
    Ycoordinate[i] += 0.2 * Vy[i];
    }
    


    }
    glEnd();
glutSwapBuffers();
}


void display(void)
{   
    drawingCircles();
}


void timer (){
    if (program_status == 1)
    check_if_collision();
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    Xcoordinate.push_back(600);
    Ycoordinate.push_back(300);
    radius.push_back(50);
    Vx.push_back(-100);
    Vy.push_back(100);

    for (int i = 0; i<4; i++){
        Xcoordinate.push_back( rand()%(window_width));
        Ycoordinate.push_back( rand()%(window_width));
        radius.push_back(defaultRadius);
        Vx.push_back( (rand()%2 - 0.5)*2* (rand()%4 ) *25 + 50  );
        Vy.push_back( (rand()%2 - 0.5)*2* (rand()%4) *25 + 50  );
    }

    
    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(window_width, window_hight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hopefully this works");
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, (GLdouble) window_width, 0.0, (GLdouble) window_hight );
    glTranslatef(-0.5, -0.5, 0);
    glPointSize(3);

    glutIdleFunc(timer);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

                    //primitive physics
                    // int a;
                    // a = Vx[i];
                    //     Vx[i] = Vx[j];
                    //     Vx[j] = a;    
                    // a = Vy[i];
                    // Vy[i] = Vy[j];
                    // Vy[j] = a;


        //fill the inside of a circle
        // switch (i%3){
        //     case 0: glColor3f(1, 0, 0);
        //     break;
        //     case 1: glColor3f(0, 1, 0);
        //     break;
        //     case 2: glColor3f(0, 0, 1);
        // }
        // for (int j = x - 1; j>=radius[i]-x; j--){
        // glVertex2i(Xcoordinate[i] + j, Ycoordinate[i] + y);
        // glVertex2i(Xcoordinate[i] + y, Ycoordinate[i] + j);
        // glVertex2i(Xcoordinate[i] - y, Ycoordinate[i] + j);
        // glVertex2i(Xcoordinate[i] - j, Ycoordinate[i] + y);
        // glVertex2i(Xcoordinate[i] - j, Ycoordinate[i] - y);
        // glVertex2i(Xcoordinate[i] - y, Ycoordinate[i] - j);
        // glVertex2i(Xcoordinate[i] + y, Ycoordinate[i] - j);
        // glVertex2i(Xcoordinate[i] + j, Ycoordinate[i] - y);
        // }
        