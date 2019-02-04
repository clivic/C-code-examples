//******************************************************************
// SPECIFICATION FILE (time.h)
// This file gives the specification of a Time abstract data type
//******************************************************************
#ifndef TIME_H
#define TIME_H

class Time
{
public:
    void Set( /* in */ int hours,
              /* in */ int minutes,
              /* in */ int seconds );
        // Precondition:
        //     0 <= hours <= 23  &&  0 <= minutes <= 59
        //  && 0 <= seconds <= 59
        // Postcondition:
        //     Time is set according to the incoming parameters

    void Increment();
        // Postcondition:
        //     Time has been advanced by one second, with
        //     23:59:59 wrapping around to 0:0:0

    virtual void Write() const;
        // Postcondition:
        //     Time has been output in the form HH:MM:SS

    Time( /* in */ int initHrs,
          /* in */ int initMins,
          /* in */ int initSecs );
        // Precondition:
        //     0 <= initHrs <= 23  &&  0 <= initMins <= 59
        //  && 0 <= initSecs <= 59
        // Postcondition:
        //     Class object is constructed
        //  && Time is set according to the incoming parameters

    Time();
        // Postcondition:
        //     Class object is constructed  &&  Time is 0:0:0
private:
    int hrs;
    int mins;
    int secs;
};
#endif
