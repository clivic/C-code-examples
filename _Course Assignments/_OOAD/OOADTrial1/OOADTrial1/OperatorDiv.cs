using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOADTrial1
{
    class OperatorDiv : Observer, Display
    {
        protected Subject infoFrom;

        public int Num { get; set; }

        public OperatorDiv(Subject iF)
        {
            infoFrom = iF;
            RegisterSubscription();
        }

        protected void RegisterSubscription()
        {
            infoFrom.AttachObserver(this);
        }

        public void Update(int x)
        {
            Num = x;
        }

        public void Display()
        {
            int result = Num / 3;
            System.Console.WriteLine("Divide: "+Num + " div " + "3 is " + result + ".\n");
        }
    }
}
