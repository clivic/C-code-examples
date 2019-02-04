#include "PhotoList.h"
#include "test_time_efficiency.h"

void instruction()
{
	printf("Welcome to the photolist in DOS!\n\n");
	printf("Menu:\n");
	printf("[1]: insert\n");
	printf("[2]: Remove\n");
	printf("[3]: replace\n");
	printf("[4]: search (by Title)\n");
	printf("[5]: search (by Location)\n");
	printf("[6]: Print\n");
	printf("[7]: Test for title search\n");
	printf("[8]: Test for location search\n");
	cout << flush;
}

void main()
{
	//Loading
	cout << "Photoes Loading..." << endl;
	PhotoList picLibrary;
	if (picLibrary.Initialization() == success)
	{
		cout << "PhotoList is initialized." << endl << "Sorting..." << endl;
		picLibrary.Sort();
	}

	//Printing
	printf("Printing...\n");
	picLibrary.Print();
	printf("Printing finished.\n");
	cout << flush;

	string identifier, name, location;		//location is place
	//int num, length, breath, size, frequency;
	//long photoedtime;
	string chName, map, smap, splace;
	string owner;
	
	//int position;

	cout << "Do you want to do some operation? (please input \"yes\" or \"no\")" << endl;
	string response;
	cin >> response;
	while (response != "no") 
	{
		if (response == "yes") 
		{
			system("cls");
			instruction();
			cout << "So, what do you want to do?" << endl;
			char demand;
			cin >> demand;

			if (demand == '1') 
			{
				//Insert
				cout << "Please input the info. below:\n"
					<< "file name? "; Cin(identifier);
				cout << "title? "; Cin(name);
				cout << "location? "; Cin(location);
				cout << "Chinese name? "; Cin(chName);
				cout << "map? "; Cin(map);
				cout << "superior map? "; Cin(smap);
				cout << "superior location? "; Cin(splace);
				PhotoRecord  item1
					(picLibrary.Size(), identifier, 0, 0,
					0, 0, chName, name, map,
					location, smap, splace, owner, 0);
			}

			else if (demand == '2') 
			{
				cout << "Please input the filename: ";
				cin >> identifier;

				PhotoRecord  item2
					(0, identifier, 0, 0, 
					0, 0, chName, name, map, 
					location, smap, splace, owner, 0);
				if (picLibrary.Remove(item2) == success)
					cout << "deleted:" << item2 << endl;
			}

			else if (demand == '3')
			{
				int choice;
				//Replace
				cout << "title is?" << endl;
				Cin(name);
				PhotoRecord  item3; int pos; string tmpName;
				if (picLibrary.SearchByKey(name, item3, pos) != not_present)
					cout << "Not found." << endl;
				else
				{
					cout << "What to replace?\n"
						<< "[1] title\n"
						<< "[2] Chinese name\n"
						<< "[3] owner: " << flush;
					Cin(choice);

					if (choice == 1)
					{
						cout << "Please input the title: ";
						Cin(tmpName);
						item3.ModifyKey(tmpName);
					}
					else if (choice == 2)
					{
						cout << "Please input the Chinese name: ";
						Cin(tmpName);
						item3.ModifyChName(tmpName);
					}
					else if (choice == 3)
					{
						string tmpstring;
						cout << "Please input the owner's name: ";
						Cin(tmpstring);
						item3.ModifyOwnerName(tmpstring);
					}
					else
					{
						cout << "Invalid input, do nothing." << endl;
					}

					if (picLibrary.Replace(item3) == success)
					{
						cout << "Replace:" << item3 << endl;
						cout << "Succesfully!" << endl;
					}
					else
						cerr << "WANRING: Can't replace the item." << endl;
				}
			}

			else if (demand == '4')
			{
				cout << "Please input a title: ";
				cin >> name;
				cout << endl;

				int n;
				List<Node<PhotoRecord> * > items;		//prestore 10 space for pictures in same name

				if (picLibrary.SearchByName(name, n, items) == success)
				{
					for (int k = 0; k < n; k++)
					{
						Node<PhotoRecord> *pr; items.Retrieve(k, pr);
						cout << pr->entry;
					}
					cout << endl;
				}
				else
					cout << "not present" << endl;
			}

			else if (demand == '5')
			{
				//searchByLocation
				cout << "location: ";
				cin >> location;
				cout << endl;

				int n;
				List<Node<PhotoRecord> * > items;

				if (picLibrary.SearchByPlace(location, n, items) == success)
				{
					for (int k = 0; k<n; k++)
					{
						Node<PhotoRecord> *pr; items.Retrieve(k, pr);
						cout << pr->entry;
					}
					cout << endl;
				}
				else
					cout << "Not present." << endl;
			}

			else if (demand == '6')
				picLibrary.Print();

			else if (demand == '7')
			{
				double wholeTime = 0.0;
				cout << "Please input 10 names for search:\n";
				QueryPerformanceFrequency(&frequ);
				int n;	List<Node<PhotoRecord> * > items;	//dummy
				string name = "";
				for (int i = 0; i < 10; i++)
				{
					printf("%d: ", i + 1);
					Cin(name);
					QueryPerformanceCounter(&start);
					picLibrary.SearchByName(name, n, items);
					QueryPerformanceCounter(&over);
					wholeTime += (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart;
				}
				cout << left << setw(25) << " By name search time: "
					<< fixed << wholeTime << "(s)." << endl;
			}

			else if (demand == '8')
			{
				double wholeTime = 0.0;
				cout << "Please input 10 locations for search:\n";
				QueryPerformanceFrequency(&frequ);
				int n;	List<Node<PhotoRecord> * > items;	//dummy
				string place = "";
				for (int i = 0; i < 10; i++)
				{
					printf("%d: ", i + 1);
					Cin(place);
					QueryPerformanceCounter(&start);
					picLibrary.SearchByName(place, n, items);
					QueryPerformanceCounter(&over);
					wholeTime += (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart;
				}
				cout << left << setw(25) << " By location search time: "
					<< fixed << wholeTime << "(s)." << endl;
			}
			else
				cout << "The damand number you input is invalid." << endl;

			cout << "Do you want to do some operation? (please input \"yes\" or \"no\")" << endl;
		}
		else {
			cout << "Please input a valid operation." << endl
				<< "Do you want to do some operation? (please input \"yes\" or \"no\")" << endl;
		}
		cin >> response;
	}
	picLibrary.Clear();
}