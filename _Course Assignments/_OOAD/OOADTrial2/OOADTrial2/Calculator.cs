using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOADTrial2
{
    public abstract class Calculator
    {
        protected CalBehavior calBehavior;

        public decimal Cal(decimal num)
        {
            return calBehavior.Cal(num);
        }
    }

    public class CalculatorDiv : Calculator
    {
        // By singleton
        static protected CalculatorDiv instance;

        protected CalculatorDiv()
        {
            calBehavior = new CBDiv();
        }

        static public CalculatorDiv GetInstance()
        {
            if (instance == null)
            {
                instance = new CalculatorDiv();
            }
            return instance;
        }
    }

    public class CalculatorMod : Calculator
    {
        // By singleton
        static protected CalculatorMod instance;

        protected CalculatorMod()
        {
            calBehavior = new CBMod();
        }

        static public CalculatorMod GetInstance()
        {
            if (instance == null)
            {
                instance = new CalculatorMod();
            }
            return instance;
        }
    }
}
