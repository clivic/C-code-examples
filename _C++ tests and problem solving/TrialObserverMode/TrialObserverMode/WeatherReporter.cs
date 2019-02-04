using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialObserverMode
{
    class WeatherReporter : Observer, Display
    {
        protected float temperature { get; set; }
        protected float humidity { get; set; }

        protected Subject infoFrom;

        public WeatherReporter(Subject iF)
        {
            infoFrom = iF;
            RegisterSubscription();
        }

        protected void RegisterSubscription()
        {
            infoFrom.AttachObserver(this);
        }

        public void Update(float t, float h, float p)
        {
            temperature = t;
            humidity = h;
            Display();
        }

        public void Display()
        {
            System.Console.WriteLine("Current conditions : " + temperature + " F degrees  and " + humidity + " % humidity. ");
        }
    }
}
