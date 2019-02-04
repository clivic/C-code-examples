/*************************************************************************
The input fommat:
1 2 3
4 5 6
7 8

1 2 3 abc
4 5 6 df
7 8

1,2,3
4,5,6
7,8
*************************************************************************/

#include <iostream >
using namespace std;

int main ()
{
    cout << "inter the values as shown"  << endl;
    
    int  a, b, c, d, e, f, g, h;

    cin  >> a  >> b  >> c;
    cin.ignore(80, '\n');
    cin >> d  >> e  >> f;
    cin.ignore(80, '\n');
    cin  >> g  >> h;
    cout  << " a "  << a  << "   b "  << b  << "   c "  << c  << endl;
    cout  << " d "  << d  << "   e "  << e  << "   f "  << f  << endl;
    cout  << " g "  << g  << "   h "  << h    << endl;
    return 0;
}
