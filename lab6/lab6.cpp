#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;



bool check_if_in_dictionary(vector <char> &word, const ofstream &dictionary)
{
    int i = 0;
    while (!dictionary.eof()){
        string str = "";
        getline(dictionary, str);
        for (int j = 0; j < word.size(); j++){
            if (str[j] != word[j]){
                break;
            }
        }
        if (str[word.size()] == ' ')
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::vector <char> word;
    char text[255];
    ofstream output;
    output.open("output.txt");
    ofstream dictionary;
    dictionary.open("dictionary.txt");
    int i = 0;
    int j = 0;
    while (i < 255 && text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            while (isalpha(text[i]))
            {
                word[j] = text[i];
                i++;
                j++;
            }
            word[j] = '\0';

            if (check_if_in_dictionary(word, dictionary) == true)
            {
                
            }
        
        
        }
        else
        {
            output << text[i];
            i++;
        }
    }
    output << EOF;
    dictionary.close();
    output.close();
    return 0;
}
