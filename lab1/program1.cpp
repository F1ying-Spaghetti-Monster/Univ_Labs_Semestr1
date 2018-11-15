#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    cout << "Hello there, type in how many prime numbers do you need: ";

    int amountofPrimesNeeded;
    cin >> amountofPrimesNeeded;
    int A[1000] = {0};

    unsigned long N1 = 0; //numenator of our rational fraction
    unsigned long D1 = 1; //denominator of our rational fraction
    int i = 2;
    //    vector <int>  primes;

    while (amountofPrimesNeeded > 0)
    {
        if (A[i] == 0)
        {
            for (int j = i * i; j <= 1000; j += i)
            {
                A[j] = 1;
            }
            //            primes.push_back (i);
            i == 2 ? cout << "1/" << i : cout << " + 1/" << i;

            if (1.0 * N1 * i + D1 / i > 1.0 * pow(2, sizeof(unsigned long) * 8))            // Overflow check
            { 
                cout << endl
                     << "Unfortunatly, this program can't proceed properly, because"
                     << " \"unsigned long\" type can't handle such a large numbers ( > 2^64)." << endl;
                return -1;
            }
            N1 = N1 * i + D1;
            D1 *= i;
            amountofPrimesNeeded -=1;
        }
        ++i;
    }

    cout << " = " << 1.0 * N1 / D1 << endl
         << "The fraction is equal to: " << N1 << "/" << D1;

    // there's no need to check wether N1 and D1 share a multiplier, because it's mathematicly impossible for them to do so.
    // there for the fraction can't be simplified.
    /* 
    int gcd(int N1, int D1) {
    return D1 == 0 ? N1 : gcd(D1, N1 % D1);
}

    */

    cout << endl
         << "Everything seemed to work fine, have a nice day!"
         << endl;

    return 0;
}