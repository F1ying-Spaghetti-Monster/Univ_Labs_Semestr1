#include <iostream>
#include <math.h>

using namespace std;


int distanceBetween2Points (int x1, int y1, int x2, int y2){
    return sqrt(( x2 - x1 ) * (x2 - x1) + ( y2 - y1 ) * (y2 - y1));
}

int triangleAreaGeron ( double a, double b, double c){
    double p = (a + b + c) / 2;
    return sqrt (p * ( p - a) * (p - b) * (p - c));
}

int triangleAreaCoordinates (int Ax, int Ay, int Bx, int By, int Cx, int Cy){
return( Bx * abs (Cx - Ax) + Cx * abs (Bx - Ax)) / 2;
}
int main(int argc, char const *argv[])
{
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
    
    double S1 = triangleAreaCoordinates (Ax, Ay, Bx, By, Cx, Cy);
    // double S2;
    // S1 == S2 ? cout << "Point is inside a triangle" :  cout << "Point is outside a triangle";
    cout << S1;
    return 0;
}
