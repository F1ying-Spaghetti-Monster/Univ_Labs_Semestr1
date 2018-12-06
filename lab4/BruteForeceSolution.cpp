#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> elements;
unsigned long iterations =0;
int rec (int current_number, int *sum, int goal){
    iterations++;
    for (int i=current_number+1; i!= elements.size(); i++){
        int summ = *sum + elements[i];
        if (summ == goal){
            return 1;
        }
        else rec(i,&summ, goal);
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    
    // int a=0;
    // while (cin >> a){
    //     if (a > 0) {
    //     elements.push_back(a);
    //     }
    // }
    elements.push_back(2);
        for (int i=0;i<32;i++)
    {
         elements.push_back(4);
        
    }


    int goal = 0;

   for (int i = 0; i!= elements.size(); i++){
            goal += elements[i];
        }
    if (goal % 2 == 1)
    {
        cout << "There is no solution for given numbers.\n";
        return -1;
    }
    else
        goal *= 0.5;
    
    int sum = elements[0];
    int status = 0;
   
   status = rec(0, &sum, goal);

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
    cout << iterations << endl;
    return 0;
}

