//******************************************************************
// SPECIFICATION FILE (exttime.h)
// This file gives the specification of an ExtTime abstract data
// type.  The Time class is a public base class of ExtTime, so
// public operations of Time are also public operations of ExtTime.
//******************************************************************
#include "time.h"
#ifndef ETIME_H
#define ETIME_H

enum ZoneType {EST, CST, MST, PST, EDT, CDT, MDT, PDT};

class ExtTime : public Time
{
public:
    void Set( /* in */ int      hours,
              /* in */ int      minutes,
              /* in */ int      seconds,
              /* in */ ZoneType timeZone );
        // Precondition:
        //     0 <= hours <= 23  &&  0 <= minutes <= 59
        //  && 0 <= seconds <= 59  &&  timeZone is assigned
        // Postcondition:
        //     Time is set according to the incoming parameters

	void Write() const;
        // Postcondition:
        //     Time has been output in the form HH:MM:SS ZZZ
        //     where ZZZ is the time zone

    ExtTime( /* in */ int      initHrs,
             /* in */ int      initMins,
             /* in */ int      initSecs,
             /* in */ ZoneType initZone );
        // Precondition:
        //     0 <= initHrs <= 23  &&  0 <= initMins <= 59
        //  && 0 <= initSecs <= 59  &&  initZone is assigned
        // Postcondition:
        //     Class object is constructed
        //  && Time is set according to the incoming parameters

    ExtTime();
        // Postcondition:
        //     Class object is constructed
        //  && Time is 0:0:0 Eastern Standard Time
private:
    ZoneType zone;
};

#endif 
