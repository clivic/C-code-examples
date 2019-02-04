//This is the second edition.
//version 1.1.0
#include <iostream>
#include <string>

using namespace std;
	
int main()
{
	cout << "No.2" << endl << endl;
	cout << "This program is to let you know how you weigh on the planet or other named asters "
		 << "in solar system." << endl;
	cout << "Please input your weight of kilo first and then enter the exact name of the planet." << endl
		 << "Tips: there are 9 planets in solar system, and you can also input \"moon\"." << endl
		 << "And the first character should be capitalized." << endl;
	
	//Defalut weight on earth and then on other planets.
	double weight, weightThen; 
	//Each parametres of other planets in the solar system.
	double mer(0.4155),
		   ven(0.8975),
		   ear(1.0000),
		   moo(0.1660),
		   mar(0.3507),
		   jup(2.5374),
		   sat(1.0677),
		   ura(0.8947),
		   nep(1.1794),
		   plu(0.0899);
	
	string name, planet; //name input and output
	cin >> weight >> name;

	if (name == "Mercury")
		weightThen = mer * weight;

	else if (name == "Venus")
		weightThen = ven * weight;
	
	else if (name == "Moon")
		weightThen = moo * weight;
	
	else if (name == "Mars")
		weightThen = mar * weight;
	
	else if (name == "Jupiter")
		weightThen = jup * weight;
	
	else if (name == "Saturn")
		weightThen = sat * weight;
	
	else if (name == "Uranus")
		weightThen = ura * weight;
	
	else if (name == "Neptune")
		weightThen = nep * weight;
	
	else if (name == "Pluto")
		weightThen = plu * weight;
	//Earth is solitary deal with for its "speciality"...
	else if (name == "Earth")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Earth--" << endl
			 << ear * weight << " kilograms." << ", exactly your weight input hah!" << endl;
		return 0;
	}
		//If no name matched in the athen in solar system.
	else
	{
		cout << "Perhaps the planet you've entered hasn't been detected in solar system hah..." << endl
		     << "Please enter the name again in the next running of this program." << endl;
		return 0;
	}
	
	planet = name;
	cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the " << planet << "--" << endl
			 << weightThen << " kilograms." << endl;

	return 0;

}

