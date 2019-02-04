using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialCommand
{
    public class RemoteController
    {
        Command[] slot;

        public RemoteController(int num = 1)
        {
            slot = new NoCommand[num];
        }

        public void SetCommand(int num, Command command)
        {
            if (num >= slot.Length || num < 0) return;

            slot[num] = command;
        }

        public void PressButton(int num)
        {
            if (num >= slot.Length || num < 0) return;

            slot[num].Execute();
        }
    }
}
