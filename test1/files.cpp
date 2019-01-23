#include <iostream>
#include <fstream>

using namespace std;

void delete_empty_lines(){

}

void replace_line(){

}


int main(int argc, char const *argv[])
{
    ofstream file;
    file.open("textFile.txt");
    file << "Test\n123\n";
    file.close();
    return 0;
}
