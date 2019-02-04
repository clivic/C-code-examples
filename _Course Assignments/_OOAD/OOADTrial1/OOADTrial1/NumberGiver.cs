using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOADTrial1
{
    public class NumberGiver:Subject
    {
        // By singleton
        static protected NumberGiver instance;

        protected List<Observer> observers;

        public int Num { get; set; }

        protected NumberGiver()
        {
            Num = 0;
            observers = new List<Observer>();
        }

        protected NumberGiver(int i)
        {
            Num = i;
            observers = new List<Observer>();
        }

        static public NumberGiver GetInstance()
        {
            if (instance == null)
            {
                instance = new NumberGiver();
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
            foreach (Observer o in observers)
            {
                o.Update(Num);
            }
        }

        public void MeasurementsChanged()
        {
            NotifyObservers();
        }
    }
}
