#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> elements;
    int a = 0;
    int i = 0;
    // char input[100];
    // cin.getline(input, 100);
  
    // while (input[i] != '\0'){
    //     while (input[i] >= '0' && input[i] <= '9'){
    //         a = 10*a + input[i] - '0';
    //         i++;
    //     }
    //     if (a != 0){
    //         i--;
    //         elements.push_back(a);
    //         a = 0;
    //     }
    //     i++;
    // }
       int goal = 0;
    //     int summ=0;
    // for (int i=0;i<20;i++)
    // {
    //     int var=rand()%1000;
    //     elements.push_back(var);
    //     if (rand()%2) {summ+=var; 
    //     cout << " + " << var;
    //     }
    //     else {summ-=var;
    //     cout << " - " << var;
    //     }
    // }
    // elements.push_back(abs(summ));
 
 elements.push_back(2);
        for (int i=0;i<32;i++)
    {
         elements.push_back(4);
        
    }

    sort(elements.begin(), elements.end());

    int status = 0;
 
    i = 0;


 

    while (i != elements.size())
    {

        goal += elements[i];
        i++;
    }
    i--;
    cout << "Ordinar method:" << endl;
    if (goal % 2 == 1)
    {
        cout << "There is no solution for given numbers.\n";
        return -1;
    }
    else
        goal *= 0.5;

    int current_sum = 0;
    unsigned long iterations = 0;
    while (status == 0)
    {
        iterations++;
        current_sum += elements[i];

        if (current_sum == goal)
        {
            elements[i] *= -1;
            status = 1;
        }
        else if (current_sum < goal)
        {
            if (i == 0)
            {
                current_sum -= elements[i];
                while (elements[i] > 0)
                {
                    i++;
                }
                if (i == elements.size() - 1)
                {
                    status = -1;
                }
                else
                {
                    current_sum += elements[i];
                    elements[i] *= -1;
                    i--;
                }
            }
            else
            {
                elements[i] *= -1;
                i--;
            }
        }
        else if (current_sum > goal)
        {
            if (i == 0)
            {
                current_sum -= elements[i];
                while (elements[i] > 0)
                {
                    i++;
                }
                if (i == elements.size() - 1)
                {
                    status = -1;
                }
                else
                {
                    current_sum += elements[i];
                    elements[i] *= -1;
                    i--;
                }
            }
            else
            {
                current_sum -= elements[i];
                i--;
            }
        }
    }
    cout << iterations << endl;
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
