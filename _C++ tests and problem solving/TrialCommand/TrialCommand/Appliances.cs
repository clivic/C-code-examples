using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialCommand
{
    public abstract class Appliances
    {
        public void SwitchOn();
    }

    class Light : Appliances
    {
        public void SwitchOn()
        {

        }
    }
}
