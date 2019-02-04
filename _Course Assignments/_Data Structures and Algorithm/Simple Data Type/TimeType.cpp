#include "D:\\Visual C++ programs\\Simple Data Type\\\\\\\\\\\TimeType.h"
#include <iostream>

using namespace std;

//TimeType Implementation
void TimeType::Set( /* in */ int hours,
                    /* in */ int minutes,
                    /* in */ int seconds )
{
    hrs = hours;
    mins = minutes;
    secs = seconds;
}

void TimeType::Write() const
{
    if (hrs < 10)
        cout << '0';
    cout << hrs << ':';
    if (mins < 10)
        cout << '0';
    cout << mins << ':';
    if (secs < 10)
        cout << '0';
    cout << secs;
}