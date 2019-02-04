//******************************************************************
// IMPLEMENTATION FILE (time.cpp)
// This file implements the Time class member functions
//******************************************************************
#include "time.h"
#include <iostream>

using namespace std;

// Private members of class:
//     int hrs;
//     int mins;
//     int secs;

//******************************************************************

Time::Time( /* in */ int initHrs,
            /* in */ int initMins,
            /* in */ int initSecs )

// Constructor

// Precondition:
//     0 <= initHrs <= 23  &&  0 <= initMins <= 59
//  && 0 <= initSecs <= 59
// Postcondition:
//     hrs == initHrs  &&  mins == initMins  &&  secs == initSecs

{
    hrs = initHrs;
    mins = initMins;
    secs = initSecs;
}

//******************************************************************

Time::Time()

// Default constructor

// Postcondition:
//     hrs == 0  &&  mins == 0  &&  secs == 0

{
    hrs = 0;
    mins = 0;
    secs = 0;
}

//******************************************************************

void Time::Set( /* in */ int hours,
                /* in */ int minutes,
                /* in */ int seconds )

// Precondition:
//     0 <= hours <= 23  &&  0 <= minutes <= 59
//  && 0 <= seconds <= 59
// Postcondition:
//     hrs == hours  &&  mins == minutes  &&  secs == seconds

{
    hrs = hours;
    mins = minutes;
    secs = seconds;
}

//******************************************************************

void Time::Increment()

// Postcondition:
//     Time has been advanced by one second, with
//     23:59:59 wrapping around to 0:0:0

{
    secs++;
    if (secs > 59)
    {
        secs = 0;
        mins++;
        if (mins > 59)
        {
            mins = 0;
            hrs++;
            if (hrs > 23)
                hrs = 0;
        }
    }
}

//******************************************************************

void Time::Write() const

// Postcondition:
//     Time has been output in the form HH:MM:SS

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
