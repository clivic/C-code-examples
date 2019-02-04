//*******************************************************************
//	Directed graph specification
//	General introduction:	
//		This DiGraph implementation uses a template contains a vertex 
//		type given by client and GRAPH_SIZE specified also by client.
//	Note: 
//		using utility.h and utility.cpp
//		For topological using or testing DiGraphs, VertexNum can be just 
//		of int type representing number of the vertices.
//*******************************************************************
#ifndef DIGRAPH
#define DIGRAPH
#include "Linked_List.h"
#include "Linked_Queue.h"

typedef int VertexNum;

struct Vertex
{
	//data members
	int others;

	//methods
	void Clear();
	Vertex(int defaultOthers = 0);
};

template <VertexNum graphSize>
class Digraph 
{
public:
	Digraph();
	void LoadTestGraph();
	void AddNode(Vertex vertex);

	//Have no time to implment now sorry
	//void Read();
	//void Write();

	//two methods of sorting
	void DepthSort(List<VertexNum> &topologicalOrder);
	void BreadthSort(List<VertexNum> &topologicalOrder);
private:
	//data members
	int count;
	List<VertexNum> neighbors[graphSize];	//number of vertice
	Vertex vertice[graphSize];				//info. of each vertex


	//auxilary functions
	void RecursiveDepthSort(VertexNum v, bool visited[],
		List<VertexNum> &topologicalOrder);
};

//*******************************************************************

//	Directed graph implementation
template <VertexNum graphSize>
Digraph<graphSize>::Digraph()
{
	count = 0;
	for (int i = 0; i < graphSize; i++)
		vertice[i].Clear();

	for (int i = 0; i < graphSize; i++)
		neighbors[i].Clear();
}

template <VertexNum graphSize>
void Digraph<graphSize>::AddNode(Vertex vertex)
//	Post:	Add a Node into the graph, with the vertex info.
{
	vertice[count]
}

template <VertexNum graphSize>
void Digraph<graphSize>::LoadTestGraph()
//	Pre:	graphSize should >= 10.
//	Post:	This is a dummy function that reads in a particular graph
//			on second Green book's Page 580.
//	Note:	This function is just for test and for the sake of saving
//			time.
{
	if (graphSize < 10)
		cerr << "Warning: Test loading failure -- graphSize should >= 10." << endl;
	else
	{
		neighbors[0].Insert(neighbors[0].Size(), 1);
		neighbors[0].Insert(neighbors[0].Size(), 5);
		neighbors[1].Insert(neighbors[1].Size(), 7);
		neighbors[3].Insert(neighbors[3].Size(), 2);
		neighbors[3].Insert(neighbors[3].Size(), 4);
		neighbors[3].Insert(neighbors[3].Size(), 7);
		neighbors[3].Insert(neighbors[3].Size(), 8);
		neighbors[4].Insert(neighbors[4].Size(), 8);
		neighbors[6].Insert(neighbors[6].Size(), 0);
		neighbors[6].Insert(neighbors[6].Size(), 1);
		neighbors[6].Insert(neighbors[6].Size(), 2);
		neighbors[8].Insert(neighbors[8].Size(), 2);
		neighbors[8].Insert(neighbors[8].Size(), 7);
		neighbors[9].Insert(neighbors[9].Size(), 4);
		cout << "Loaded successfully!" << endl;
	}
}

template <VertexNum graphSize> 
void Digraph<graphSize>::DepthSort(List<VertexNum> &topologicalOrder)
//	Post:	The vertices of the Digraph are placed into List 
//			topologicalOrder with a depth-first traversal of those 
//			vertices that do not belong to a cycle.
//	Uses:	Methods of class List, and function RecursiveDepthSort to 
//			perform depth-first traversal. 
{
	bool visited[graphSize];
	VertexNum v;
	for (v = 0; v < count; v++) visited[v] = false;
	topologicalOrder.Clear();
	for (v = 0; v < count; v++)
		if (!visited[v]) //Add v and its successors into topological order.
			RecursiveDepthSort(v, visited, topologicalOrder);
}

template <VertexNum graphSize> 
void Digraph<graphSize>::RecursiveDepthSort(VertexNum v, bool *visited, List<VertexNum> &topologicalOrder)
//	Pre:	VertexNum v of the Digraph does not belong to the partially 
//			completed List topologicalOrder.
//	Post:	All the successors of v and finally v itself are added 
//			to topologicalOrder with a depth-first search.
//	Uses:	Methods of class List and the function RecursiveDepthSort. 
{
	visited[v] = true;
	int degree = neighbors[v].Size();
	for (int i = 0; i < degree; i++)
	{
		VertexNum w;					//A(neighboring) successor of v
		neighbors[v].Retrieve(i, w);
		if (!visited[w])			//Order the successors of w.
			RecursiveDepthSort(w, visited, topologicalOrder);
	}
	topologicalOrder.Insert(0, v);	//Put v into topologicalOrder.
}

template <VertexNum graphSize> 
void Digraph<graphSize>::BreadthSort(List<VertexNum> &topologicalOrder)
//	Post:	The vertices of the Digraph are arranged into the List 
//			topologicalOrder which is found with a breadth-first 
//			traversal of those vertices that do not belong to a cycle.
//	Uses:	Methods of classes Queue and List. 
{
	topologicalOrder.Clear();
	VertexNum v, w;
	int predecessorCount[graphSize];
	for (v = 0; v < count; v++) predecessorCount[v] = 0;
	for (v = 0; v < count; v++)
		for (int i = 0; i < neighbors[v].Size(); i++)
		{
			neighbors[v].Retrieve(i, w); //Loop over all edges v--w.
			predecessorCount[w]++;
		}
	Queue<VertexNum> readyToProcess;
	for (v = 0; v < count; v++)
		if (predecessorCount[v] == 0)	
			readyToProcess.Append(v);
	while (!readyToProcess.Empty())
	{
		readyToProcess.Retrieve(v);
		topologicalOrder.Insert(topologicalOrder.Size(), v);
		for (int j = 0; j < neighbors[v].Size(); j++)
		{
			neighbors[v].Retrieve(j, w); //Traverse successors of v.
			predecessorCount[w]--;
			if (predecessorCount[w] == 0)
				readyToProcess.Append(w);
		}
		readyToProcess.Serve();
	}
}



#endif