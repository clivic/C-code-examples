//******************************************************************
// TestExtTime program
// This is a very simple client of the ExtTime class
//******************************************************************
#include "exttime.h"
#include <iostream>

using namespace std;

int main()
{
    ExtTime time1(5, 30, 0, CDT);
    ExtTime time2;
    int     count;

    cout << "time1: ";
    time1.Write();
    cout << "  time2: ";
    time2.Write();
    cout << endl;

    time2.Set(23, 59, 55, PST);
    cout << "New time2: ";
    time2.Write();
    cout << endl;

    cout << "Incrementing time2:" << endl;
    for (count = 1; count <= 10; count++)
    {
        time2.Write();
        cout << ' ';
        time2.Increment();
    }
    return 0;
}
