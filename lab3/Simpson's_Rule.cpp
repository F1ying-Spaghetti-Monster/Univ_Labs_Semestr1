#include <iostream>
#include <math.h>

using namespace std;

double func (double x){

    return x*x*x*x;
}

double diriv4 (double x){
    return 24;
}

double SimpsonsMethod (double range1, double range2, int number_of_steps){

    double step_lenght = (range2 - range1) / number_of_steps;
    double value = 0.5 * ( func(range1) + func(range2) );
    for (double a = range1 + step_lenght; a < range2; a+= step_lenght){
        value += func(a) + 2*func(a - 0.5 * step_lenght);
    }
    // value += 2* func(range2 - 0.5 * step_lenght);
    value *= step_lenght/3;

    return value;
}

double calc_error (double range1, double range2, int number_of_steps){
    return pow(range2 - range1, 5) * 24 /(180* pow(number_of_steps, 4) );
}

int main(int argc, char const *argv[])
{
    double Start_of_integral;
    double End_of_integral;
    int Number_of_Steps;

    cout << "Type in integal bounds: " << endl;
    cout << "Begin:  ";
    cin >> Start_of_integral; 
    cout <<  endl << "End:  ";
    cin >> End_of_integral;   
    cout << endl << "Number of steps:  ";
    cin >> Number_of_Steps;

    double sum = SimpsonsMethod(Start_of_integral, End_of_integral, Number_of_Steps);
    double error = calc_error(Start_of_integral, End_of_integral, Number_of_Steps);

    cout << "Integral value is: " << sum << endl;
    cout << "Error is: " << error << endl;
    return 0;
}
