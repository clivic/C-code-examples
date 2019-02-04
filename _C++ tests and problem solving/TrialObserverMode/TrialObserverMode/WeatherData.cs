using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialObserverMode
{
    public class WeatherData : Subject
    {
        // By singleton
        static protected WeatherData instance;

        protected List<Observer> observers;
        protected float temperature;
        protected float humidity;
        protected float pressure;

        public float Temperature { get; set; }

        public float Humidity { get; set; }

        public float Pressure { get; set; }

        protected WeatherData()
        {
            observers = new List<Observer>();
        }

        static public WeatherData GetInstance()
        {
            if (instance == null)
            {
                instance = new WeatherData();
            }
            return instance;
        }

        public void AttachObserver(Observer o)
        {
            observers.Add(o);
        }

        public void DettachObserver(Observer o)
        {
            int i = observers.IndexOf(o);
            if (i >= 0)
            {
                observers.Remove(o);
            }
        }

        public void NotifyObservers()
        {
            WeatherData wTemp = GetInstance();
            foreach (Observer o in observers)
            {
                o.Update(Temperature, Humidity, Pressure);
            }
        }

        public void MeasurementsChanged()
        {
            NotifyObservers();
        }        
    }
}
