#include <iostream>

using namespace std;
namespace MarioRotunno
{
    int x;
    int y;
}

int main()
{
    MarioRotunno::x=1;
    MarioRotunno::y=1;

    cout<<"Mario ha x mele e y pere: "<<MarioRotunno::x<<" "<<MarioRotunno::y<< endl;
    return 0;
}
