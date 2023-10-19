#include <iostream>
using namespace std;



int main()
{
    int licz = 300;
    while (licz < 1201) {
        if (licz % 2 == 1) {
            cout << licz << " ";
        }
        else if (licz % 400 == 0) {
            cout << endl;
        }
        else if (licz % 100 == 0) {
            cout << "*** ";
        }
        licz++;
    }
}
