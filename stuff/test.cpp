#include <iostream>
#include <cstdio>

int main(int argc, char* argv[])
{
  using namespace std;
  freopen( "logs/output.txt", "w", stdout );
  freopen( "logs/error.txt", "w", stderr );

  cout << "Output message" << endl;
  cerr << "Error message" << endl;
}