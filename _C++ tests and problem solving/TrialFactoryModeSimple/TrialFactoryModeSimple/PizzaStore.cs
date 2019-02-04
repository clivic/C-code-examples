using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialFactoryModeSimple
{
    public class PizzaStore
    {
        protected FactoryPizza factoryPizza;

        public PizzaStore(FactoryPizza fP)
        {
            factoryPizza = fP;
        }

        public Pizza OrderPizza(String type)
        {
            Pizza pizza = null;
            pizza = factoryPizza.CreatePizza(type);
            pizza.Prepare();
            pizza.Bake();
            pizza.Cut();
            pizza.Box();
            return pizza;
        }
    }
}
