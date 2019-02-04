using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialCommand
{
    interface Command
    {
        public void Execute();
    }

    //*************************************************************************

    public class LightOnCommand : Command
    {
        Light light;
        public LightOnCommand(Light light)
        {
            this.light = light;
        }
        public void Execute()
        {
            light.SwitchOn();
        }
    }

    public class NoCommand : Command
    {
        public void execute()
        {

        }
    }

}
