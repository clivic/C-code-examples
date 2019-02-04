using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOADTrial1
{
    public interface Subject
    {
        void AttachObserver(Observer o);

        void DettachObserver(Observer o);

        void NotifyObservers();
    }

    public interface Observer
    {
        void Update(int x);
    }

    public interface Display
    {
        void Display();
    }
}
