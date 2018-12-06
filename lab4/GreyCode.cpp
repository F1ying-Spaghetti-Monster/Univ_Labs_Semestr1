#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> str;
    for (int i=0; i<20; i++){
        str.push_back(rand()%2);
        cout << str[i];
    }

    vector <int> grey;
    grey.push_back(str[0]);
    cout << endl << grey[0];
    for (int i = 1; i!= str.size(); i++){
        grey.push_back((str[i] + str [i-1])%2);
        cout << grey[i];
    }
    cout <<endl;

    vector <int> str2;
    str2.push_back(grey[0]);
    cout << str2[0];
    for(int i =1; i!= grey.size(); i++){
        str2.push_back((abs(grey[i] - str2[i-1]))%2);
        cout << str2[i];
    }

    return 0;
}
