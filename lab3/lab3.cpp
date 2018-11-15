#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <thread>

using namespace std;

double func(double x){
    return x*x*x*x;
}

double derivitive3(double x){
    return 24*x;
}

int main(int argc, char *argv[])
{
    double Start_of_integral;
    double End_of_integral;

    cout << "type in integal bounds: " << endl;
    cout << "Begin:  ";
    cin >> Start_of_integral; 
    cout <<  endl << "End:  ";
    cin >> End_of_integral;

    int Number_of_Steps;
    cout << endl << "Number of steps:  ";
    cin >> Number_of_Steps;

    double Step_lenght = (End_of_integral - Start_of_integral)/Number_of_Steps;
    double Integral_value = 1.0* (func(Start_of_integral) + func(End_of_integral))/2;

    double f3_max = 0;
    double eror = 0;

    {
        double a = Start_of_integral;
        double b = a + Step_lenght;
        while (a < End_of_integral){      
            Integral_value += func(b) + 2 * func( (a+b)/2);

   
            double x = abs(derivitive3(a));
            if (x > f3_max) 
                f3_max = x;

            a = b;
            b+= Step_lenght;
        }
    }
    Integral_value *= Step_lenght/3;
    cout << endl << Integral_value << endl;

    cout << "Eror =  " << eror << endl;
    

    return 0;
}
