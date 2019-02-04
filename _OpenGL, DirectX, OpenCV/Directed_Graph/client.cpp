//*******************************************************************
//	client -- test for directed graph's Depth-first and Breadth-first 
//	algorithm
//*******************************************************************
#include "Directed_Graph.h"

template <class List_entry>
void PrintEntry(List_entry &entry);

void main()
{
	Digraph<10> diGraph;
	List<int> result;
	diGraph.LoadTestGraph();
	printf("Test for directed graph:\n");
	printf("for the graph on P580:\n");
	printf("Depth-first ordering:\n");
	diGraph.DepthSort(result);
	result.Traverse(PrintEntry);
	cout << endl;
	result.Clear();

	printf("Breadth-first ordering:\n");
	diGraph.BreadthSort(result);
	result.Traverse(PrintEntry);
	cout << endl;
}

template <class List_entry>
void PrintEntry(List_entry &entry)
{
	cout << entry << ' ';
}