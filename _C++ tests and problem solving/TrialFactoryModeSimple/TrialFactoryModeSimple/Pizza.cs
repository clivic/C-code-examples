using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialFactoryModeSimple
{
    abstract public class Pizza
    {
        public void Prepare();
        public void Bake();
        public void Cut();
        public void Box();
    }

    //*************************************************************************

    public class VeggiePizza : Pizza
    {

    }

    public class CheesePizza : Pizza
    {

    }

    public class ClamPizza : Pizza
    {

    }

    public class PepproniPizza : Pizza
    {

    }

    public class GreekPizza : Pizza
    {

    }

    public class DummyPizza : Pizza
    {

    }
}
