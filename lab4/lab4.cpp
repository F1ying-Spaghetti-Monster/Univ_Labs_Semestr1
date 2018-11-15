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

    sort(elements.begin(), elements.end());
    
    int status = 0;
    int plus_sum = 0;
    for (int i = 0; i != elements.size(); i++){
        // cout << elements[i];
        plus_sum += elements[i];
    }

    int current_element = elements.size()-1;
    while (status == 0){
        elements[current_element] = -elements[current_element];
        plus_sum += 2*elements[current_element];        
        if (plus_sum == 0){
            status = 1;
        }
        if (plus_sum > 0){
            current_element--;
            if (current_element == -1){
                elements[current_element] = -elements[current_element];
                status = -1;
            }
        }
        if (plus_sum < 0){
            elements[current_element] = -elements[current_element];
            plus_sum += 2*elements[current_element];
            while (elements[current_element] >0 && current_element != elements.size()) {
                current_element ++;
            }
            if (current_element == elements.size()){
                elements[current_element] = -elements[current_element];
                status = -1;
            }
            else {
                elements[current_element] = -elements[current_element];
                plus_sum += 2*elements[current_element];
                current_element --;
            }
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

