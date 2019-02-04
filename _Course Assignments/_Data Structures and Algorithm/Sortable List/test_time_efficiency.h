//*******************************************************************
//	Time efficiency test necessary files
//	It is the standard windows' method to determine how much time a 
//	function use during execution.
//	Using like this:
//		QueryPerformanceFrequency(&frequ);	//(1) get frequency of CPU
//		QueryPerformanceCounter(&start);	//(2) get start time
//		Vocabulary.Search(position, item5);	//function use
//		QueryPerformanceCounter(&over);		//(3) get end time 
//		cout << "time: " << (end.QuadPart - begin.QuadPart) / (double)frequ.QuadPart << endl;
//											//(4) get execution time
//*******************************************************************
#include <time.h>
#include <Windows.h>

LARGE_INTEGER start;
LARGE_INTEGER over;
LARGE_INTEGER frequ;
