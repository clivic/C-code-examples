using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hold_And_Attack_2._0
{
    public static class HAMath
    {
        //Convert seconds to beats with the given bpm
        public static double SecondsToBeats(double seconds, double bpm)
        {
            return seconds * bpm / 60;
        }

        //Convert beats to seconds in the given bpm
        public static double BeatsToSeconds(double beats, double bpm)
        {
            return (beats * 60) / bpm;
        }
    }
}
