using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialObserverMode
{
    public interface Subject
    {
        void AttachObserver(Observer o);

        void DettachObserver(Observer o);

        void NotifyObservers();
    }   
 
    public interface Observer
    {
        void Update(float temperature, float humidity, float pressure);
    }

    public interface Display
    {
        void Display();
    }
}
