#include <iostream>
#include <string.h>

using namespace std;

int convertToBase10 (char *str, int base){
    int stringLength = strlen(str);
    int power = 1;
    int result = 0;
    int currentCharacter;

    for (int i =  stringLength-1; i>=0; --i){
        currentCharacter = str[i] - '0';
        result += currentCharacter * power;
        power *= base;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    char str[4];
    int currentBase = 10;
    int desiredBase = 2;
    int answer = 0;

    cout << "Enter the number you want to convert and it's current base:"<< endl;
    cin >> str >> currentBase;
    cout << "Enter the base you want to convert your number to:"<< endl;
    cin >> desiredBase;

    if (currentBase != 10 && currentBase != desiredBase) {
        answer = convertToBase10(str, currentBase);
        cout << answer;
    }
    return 0;
}
