//******************************************************************
// IMPLEMENTATION FILE (exttime.cpp)
// This file implements the ExtTime member functions.
// The Time class is a public base class of ExtTime
//******************************************************************
#include "exttime.h"
#include <iostream>
#include <string>

using namespace std;

// Additional private members of class:
//     ZoneType zone;

//******************************************************************

ExtTime::ExtTime( /* in */ int      initHrs,
                  /* in */ int      initMins,
                  /* in */ int      initSecs,
                  /* in */ ZoneType initZone )

    : Time(initHrs, initMins, initSecs)

// Constructor

// Precondition:
//     0 <= initHrs <= 23  &&  0 <= initMins <= 59
//  && 0 <= initSecs <= 59  &&  initZone is assigned
// Postcondition:
//     Time is set according to initHrs, initMins, and initSecs
//     (via call to base class constructor)
//  && zone == initZone

{
    zone = initZone;
}

//******************************************************************

ExtTime::ExtTime()

// Default constructor

// Postcondition:
//     Time is 0:0:0 (via implicit call to base class's
//     default constructor)
//  && zone == EST

{
    zone = EST;
}

//******************************************************************

void ExtTime::Set( /* in */ int      hours,
                   /* in */ int      minutes,
                   /* in */ int      seconds,
                   /* in */ ZoneType timeZone )

// Precondition:
//     0 <= hours <= 23  &&  0 <= minutes <= 59
//  && 0 <= seconds <= 59  &&  timeZone is assigned
// Postcondition:
//     Time is set according to hours, minutes, and seconds
//  && zone == timeZone

{
    Time::Set(hours, minutes, seconds);
    zone = timeZone;
}

//******************************************************************

void ExtTime::Write() const

// Postcondition:
//     Time has been output in the form HH:MM:SS ZZZ
//     where ZZZ is the time zone

{
    static string zoneString[8] =
    {
        "EST", "CST", "MST", "PST", "EDT", "CDT", "MDT", "PDT"
    };

    Time::Write();
    cout << ' ' << zoneString[zone];
}
