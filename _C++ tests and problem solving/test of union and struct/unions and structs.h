#include <string>

using namespace std;

struct person
{
   string name;
   int age;
};

union weightType
{
   long wtInOunces;
   int wtInPounds;
   double wtInTons;
};
