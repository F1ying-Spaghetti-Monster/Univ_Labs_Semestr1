#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) //bugged
{
    int a, b;
    cin >> a >> b;
    int originalA = a;
    int originalB = b;
    while (a % b != 0) {
        a = a % b;
        b = b % a;
    }
    cout << originalA/b << originalB/b;
    return 0;
}
