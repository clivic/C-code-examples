using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOADTrial2
{
    public interface CalBehavior
    {
        decimal Cal(decimal num);
    }

    public class CBDiv : CalBehavior
    {
        public decimal Cal(decimal num)
        {
            return num / 3;
        }
    }

    public class CBMod : CalBehavior
    {
        public decimal Cal(decimal num)
        {
            return num % 3;
        }
    }
}
