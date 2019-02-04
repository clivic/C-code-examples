//*******************************************************************
//	Test the efficiency of sorting
//*******************************************************************
#include "Sortable_List_Char.h"
#include "test_time_efficiency.h"
#include "Random.h"

void TestAll(const SortableList<int> &numbers);
void TestForBubSort(SortableList<int> &l);
void TestForInsSort(SortableList<int> &l);
void TestForSelSort(SortableList<int> &l);
void TestForMergeSort(SortableList<int> &l);
void TestForShellSort(SortableList<int> &l);
void TestForQuickSort(SortableList<int> &l);
void TestForHeapSort(SortableList<int> &l);

//test function for RadixSort by Mr.Bao
void Print(Record &x)
{
	cout << (Key)x;
}

int main()
{
	//test for original SortableList

	SortableList <int> numbers;
	Random random;
	//*enum testType { small_test, sequencial_test, reversal_test, random_test };
	testType state;*/
	int state;
	do
	{
		cout << "Please choose the test--\n"
			<< "Press [0] sort seven numbers, or\n"
			<< "Press [1] sort 20,000 sequential increasing numbers, or\n"
			<< "Press [2] sort 20,000 sequential decreasing numbers, or\n"
			<< "Press [3] sort 20,000 random numbers: " << flush;
		Cin(state);
		switch (state)
		{
		case /*small_test*/0:
			numbers.Insert(numbers.Size(), 26);
			numbers.Insert(numbers.Size(), 33);
			numbers.Insert(numbers.Size(), 35);
			numbers.Insert(numbers.Size(), 29);
			numbers.Insert(numbers.Size(), 19);
			numbers.Insert(numbers.Size(), 12);
			numbers.Insert(numbers.Size(), 22);

			TestAll(numbers);
			break;

		case /*sequencial_test*/1:
			for (int i = 0; i < 20000; i++)
				numbers.Insert(numbers.Size(), i);

			TestAll(numbers);
			break;

		case /*reversal_test*/2:
			for (int i = 0; i < 20000; i++)
				numbers.Insert(numbers.Size(), 20000 - i);

			TestAll(numbers);
			break;

		case /*random_test*/3:
		
			for (int i = 0; i < 20000; i++)
				numbers.Insert(numbers.Size(), random.RandomInt(0, INT_MAX));

			TestAll(numbers);
			break;

		default:
			cout << "command invalid." << endl;
			break;
		}
		cout << "\nDo you wanna continue? " << flush;
		numbers.Clear();
	} while (UserSayYes());

	////test for RadixSort by Mr.Bao
	//SortableListChar mylist;
	//mylist.Insert(0, Record("rat"));
	//mylist.Insert(1, Record("mop"));
	//mylist.Insert(2, Record("cat"));
	//mylist.Insert(3, Record("map"));
	//mylist.Insert(4, Record("car"));
	//mylist.Insert(5, Record("top"));
	//mylist.Insert(6, Record("cot"));
	//mylist.Insert(7, Record("tar"));
	//mylist.Insert(8, Record("rap"));
	//cout << "The list is: " << endl;
	//mylist.Traverse(Print);

	//cout << endl << "Use radix_sort Method:" << endl;
	//mylist.RadixSort();
	//mylist.Traverse(Print);

	//cin.get();	//haul the program
}

void TestAll(const SortableList<int> &numbers)
//	Post:	Test all the seven sort methods except MergeSort
//			for it is unsuitable for huge array perhaps.
{
	SortableList<int> test = numbers;

	TestForInsSort(test); test = numbers;
	TestForSelSort(test); test = numbers;
	TestForMergeSort(test); test = numbers;
	TestForShellSort(test); test = numbers;
	TestForQuickSort(test); test = numbers;
	TestForHeapSort(test);
	//TestForBubSort(test); test = numbers;
}

void TestForBubSort(SortableList<int> &l)
//	Post:	cout the time for sorting the list l
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	l.BubbleSort();
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Bubble Sort time: " << fixed << setprecision(15)
		<< (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;
}

void TestForInsSort(SortableList<int> &l)
//	Post:	cout the time for sorting the list l
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	l.InsertionSort();
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Insertion Sort time: " << fixed << setprecision(15)
		<< (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;
}

void TestForSelSort(SortableList<int> &l)
//	Post:	cout the time for sorting the list l
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	l.SelectionSort();
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Selection Sort time: " << fixed << setprecision(15)
		<< (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;
}

void TestForMergeSort(SortableList<int> &l)
//	Post:	cout the time for sorting the list l
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	MergeSort(l);
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Merge Sort time: " << fixed << setprecision(15)
		<< (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;
}

void TestForShellSort(SortableList<int> &l)
//	Post:	cout the time for sorting the list l
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	l.ShellSort();
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Shell Sort time: " << fixed << setprecision(15)
		<< (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;
}

void TestForQuickSort(SortableList<int> &l)
//	Post:	cout the time for sorting the list l
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	l.QuickSort();
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Quick Sort time: " << fixed << setprecision(15)
		<< (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;
}

void TestForHeapSort(SortableList<int> &l)
//	Post:	cout the time for sorting the list l
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	l.HeapSort();
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Heap Sort time: " << fixed << setprecision(15)
		<< (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;

}