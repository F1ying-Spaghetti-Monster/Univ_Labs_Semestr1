#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int currentNumeralSystem = 10;
    int desiredNumeralSystem = 2;
    int currentNumber = 255;
    int answer = 0;

    // cin >> curentNumeralSystem;
    // cin >> desiredNumeralSystem;

    int i = 0;
    int k = 0;
    if (currentNumeralSystem != 10){
        int nonDecNumber = currentNumber;
        currentNumber = 0;
        int j = 0;
        while (pow (10, j) <= nonDecNumber){
            int b = pow(10, j+1);
            currentNumber += pow(currentNumeralSystem, j)*( (nonDecNumber % b ) / pow(10, j) );
            nonDecNumber -= (nonDecNumber % b );
            ++j; 
        }
        cout << "Dec number is: " << currentNumber << endl;
    }


    while (pow(desiredNumeralSystem, i) <= currentNumber)
    {
        ++i;
    }
    i -= 1;
    while (i >= 0)
    {
        
            k = currentNumber / pow(desiredNumeralSystem, i);
            currentNumber -= pow(desiredNumeralSystem, i) * k;
            if (k<10) cout << k; 
            else {
            char over10 = 55+k;
            cout << over10;
            }
            //answer += pow(10, i) * k;
        
    --i;
    }
    cout << endl;
    //cout << answer << endl;
    return 0;
}
