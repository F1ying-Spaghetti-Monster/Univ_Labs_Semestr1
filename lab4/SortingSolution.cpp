#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> elements;
    int a = 0;
    int i = 0;
    char input[100];
    cin.getline(input, 100);
  
    while (input[i] != '\0'){
        while (input[i] >= '0' && input[i] <= '9'){
            a = 10*a + input[i] - '0';
            i++;
        }
        if (a != 0){
            i--;
            elements.push_back(a);
            a = 0;
        }
        i++;
    }

    sort(elements.begin(), elements.end());

    int status = 0;
    int goal = 0;
    i = 0;
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

    int current_sum = 0;

    while (status == 0)
    {
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
