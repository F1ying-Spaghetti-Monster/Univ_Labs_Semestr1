#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    vector<int> elements;

int binary_search (int value, int left, int right){
    if (left <= right){
        int mid = left + (right - left)/2;
        if (elements[mid] == value)   
            return mid; 
        if (elements[mid] > value)  
            return binary_search(value, left, mid - 1); 
        if (elements[mid] < value)
            return binary_search(value, mid+1, right); 
    }
    return left;
}

int recursion (int goal, int current_element_ind){
    if (goal < 0){
        return -1;
    }
    int i = binary_search(goal, 0, current_element_ind -1);
    if (elements[i] == goal){
        elements[i] *= -1;
        // elements[current_element_ind] *= -1;
        return 1;
    }
    else {
        for (int j = i-1; j!=-1; j--){
        if (recursion(goal - elements[current_element_ind], j) == 1){
            elements[current_element_ind] *= -1;
            return 1;
        }
        }
    }
    return -1;
    }
    


int main(int argc, char const *argv[])
{

    int a = 0;
    int goal = 0;
    int i = 0;

    // int summ=0;
    // for (int i=0;i<25;i++)
    // {
    //     int var=rand()%1000;
    //     elements.push_back(var);
    //     if (rand()%2) summ+=var; 
    //     else summ-=var;
    // }
    // elements.push_back(abs(summ));

elements.push_back(2);
        for (int i=0;i<32;i++)
    {
         elements.push_back(4);
        
    }

cout << "Recursive method" << endl;
 
    /*while (cin >> a)
    {
        if (a > 0)
        {
            elements.push_back(a);
            goal += a;
            i++;
        }
    }*/

    sort(elements.begin(), elements.end());

    int status = 0;
    
    while (i != elements.size())
    {

        goal += elements[i];
        i++;
    }
    i--;

    if (goal % 2 == 1)
    {
        cout << "There is no solution for given numbers.\n";
        return -1;
    }
    else
        goal *= 0.5;

    if (elements[i] == goal){
        elements[i] *= -1;
        status = 1;
    }
    else
        status = recursion (goal, i);

    if (status == -1)
    {
        cout << "There is no solution for given numbers.\n";
        return -1;
    }

    if (status == 1)
    {
        cout << "Solution exists, here is one possible variant:\n";
        for (int i = 0; i != elements.size(); i++)
        {
            if (elements[i] > 0)
            {
                cout << " + " << elements[i];
            }
            else
            {
                cout << " - " << -elements[i];
            }
        }
        cout << endl;
    }

    return 0;
}
