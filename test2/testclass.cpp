#include <iostream>
using namespace std;

#include<iomanip>

int main()
{
    int x = 1.6;

    cout << setiosflags(ios::showpoint) << setprecision(2);
    cout << x;
}
