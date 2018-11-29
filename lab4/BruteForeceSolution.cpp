#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> elements;   // { 1,2,3,4,5,7 }; // 1 + 2 + 3 - 4 + 5 - 7
    int a=0;
    while (cin >> a){
        if (a > 0) {
        elements.push_back(a);
        }
    }
    cout << elements.size();

    
    int status = 0;
    while (status == 0){
        for (int i = 0; i!= elements.size(); i++){
            
        }

    }

    if (status == 1){
        cout << "Solution exists, here is one possible variant:\n";
        for (int i = 0; i != elements.size(); i++){
            if (elements[i] > 0){
                cout <<" + "<< elements[i];
            }
            else {
                cout <<" - "<< -elements[i];
            }
        }
        cout << endl;
    }
    if (status == -1){
        cout << "There is no solution for given numbers."<< endl;
    }
    
    return 0;
}

