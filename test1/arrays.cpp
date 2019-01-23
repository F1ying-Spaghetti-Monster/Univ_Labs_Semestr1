#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char string [256];
    string[255] = '\0';
    char output[256];
    char look_for[3] = {'a', 'b', 'c'};
    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == look_for[0]){
            for (int k =1; k != sizeof(look_for); k++){
                if (string[i+k] != look_for[k]){
                    
                }
            }
        }
    }
    return 0;
}
