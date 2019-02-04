using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialFactoryMode
{
    public class FactoryPizza
    {
        protected Pizza pizza;

        public Pizza CreatePizza(string type)
        {
            type = type.ToLower();

            Pizza p = null;
            if (type == "cheese")
            {
                p = new CheesePizza();
            }
            if(type == "greek")
            {
                p = new GreekPizza();
            }
            if(type == "veggie")
            {
                p = new VeggiePizza();
            }
            else
            {
                p = new DummyPizza();
            }
            return p;
        }
    }
}
