//This is the third edition.
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
	double k; //the parameter
	
	string name, planet; //name input and output
	cin >> weight >> name;

	if (name == "Mercury")
		k = 0.4155;

	else if (name == "Venus")
		k = 0.8975;
	
	else if (name == "Moon")
		k = 0.1660;
	
	else if (name == "Mars")
		k = 0.3507;
	
	else if (name == "Jupiter")
		k = 2.5374;
	
	else if (name == "Saturn")
		k = 1.0677;
	
	else if (name == "Uranus")
		k = 0.8947;
	
	else if (name == "Neptune")
		k = 1.1794;
	
	else if (name == "Pluto")
		k = 0.0899;
	//Earth is solitary deal with for its "speciality"...
	else if (name == "Earth")
	{
		k = 1.0000;
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Earth--" << endl
			 << k * weight << " kilograms." << ", exactly your weight input hah!" << endl;
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
	weightThen = k * weight;
	cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the " << planet << "--" << endl
			 << weightThen << " kilograms." << endl;

	return 0;

}

