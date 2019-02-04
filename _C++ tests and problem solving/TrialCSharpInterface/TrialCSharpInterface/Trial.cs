using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrialCSharpInterface
{
    sealed public class Trial:Outputer
    {
        public string Output()
        {
            int[] i = new int[5];
            string s = "2";
            s.Length
            return "Hi";
        }
    }

    public interface Outputer
    {
        string Output();
        
            // Test Result: Interface is ot allowed to have definitions!!!
            //return "Hello"; 
    }

    //public class TrialSub : Trial
    //// Test Result: sealed class is not allowed to be derived!!!
    //{
    //    public string Output()
    //    {
    //        return "Hello";
    //    }
    //}

    public class TrialSub : String
    // Test Result: String is a sealed System class which can't be derived!!!
    {
    }
}
