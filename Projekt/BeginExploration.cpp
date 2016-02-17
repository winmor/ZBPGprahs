#include "BeginExploration.h"
#include "Graph.h"
#include "DFSnormal.h"
#include "DFSboost.h"
#include "BFSnormal.h"
#include "BFSboost.h"
#include "FloydWarshallNormal.h"
#include "FloydWarshallBoost.h"
#include "DijkstraNormal.h"
#include "DijkstraBoost.h"
#include "BellmanFordNormal.h"
#include "BellmanFordBoost.h"
#include "JohnsonBoost.h"
#include "JohnsonNormal.h"
#include "Exploration.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <stdlib.h>

void experimentDepthFirst(const std::shared_ptr<Graph>& graph)
{
	using namespace std::chrono;

	//graf zwyk造 DFS
	std::cout << std::endl << "Depth First: " << std::endl << "Wlasna implementacja:";
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	graph->standardGraph();
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 0, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
#ifdef DEBUG
	graph->print();
#endif
	//przeszukiwanie grafu zwyk貫go
	DFSnormal(graph,1,0);
	std::cout << std::endl << graph->printTime(1, 0);
	std::cout << std::endl << "Czas obu operacji: "<< graph->calcBothTime(0);

	std::cout << std::endl << std::endl << "Implementacja boost: ";
	//graf zwyk造 boost
	begin = high_resolution_clock::now();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->boostSimpleGraph();
	graph->setExpTime(0, 1, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	//przeszukiwanie zwyk貫go boost
	DFSBoost(graph,1,1);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(1);
	
	//BFS standard

	std::cout << std::endl << "Breadth First: " << std::endl << "Wlasna implementacja:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 2, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	BFSstandard(graph, 1, 2);
	std::cout << std::endl << "Czas obu operacji: " <<  graph->calcBothTime(2);
}

void testExperiment()
{
	size_t size = 5000;
	Graph* genGraph = new Graph(size, 100);
	std::shared_ptr<Graph> graph(genGraph);
	experimentDepthFirst(graph);
	
}
void startExperiment()
{
	//testExperiment();
	exploration();
}
void testing(const std::shared_ptr<Graph>& graph)
{

	using namespace std::chrono;

	//graf zwyk造 DFS
	std::cout << std::endl << std::endl << "Depth First: " << std::endl << "Wlasna implementacja:";
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	graph->standardGraph();
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 0, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count() << std::endl;
#ifdef _DEBUG
	graph->print();
#endif
	//przeszukiwanie grafu zwyk貫go
	std::cout << std::endl;
	DFSnormal(graph, 1, 0);
	std::cout << std::endl << graph->printTime(1, 0);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(0);

	std::cout << std::endl << std::endl << "Implementacja boost: ";
	//graf zwyk造 boost
	begin = high_resolution_clock::now();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	std::cout << std::endl;
	graph->boostSimpleGraph();
	graph->setExpTime(0, 1, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	//przeszukiwanie zwyk貫go boost
	DFSBoost(graph, 1, 1);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(1);

	//BFS standard

	std::cout << std::endl << std::endl << "Breadth First: " << std::endl << "Wlasna implementacja:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 2, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	BFSstandard(graph, 1, 2);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(2);


	std::cout << std::endl << "Implementacja Boost:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 3, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	BFSBoost(graph, 1, 3);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(3);

	//Floyd-Warshall standard

	std::cout << std::endl << std::endl << "Floyd-Warshall: " << std::endl << "Wlasna implementacja:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 4, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	FloydWarshallNormal(graph, 1, 4);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(4);


	std::cout << std::endl << "Implementacja Boost:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 5, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	FloydWarshallBoost(graph, 1, 5);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(5);


	//Dijkstra standard

	std::cout << std::endl << std::endl << "Dijkstra: " << std::endl << "Wlasna implementacja:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 6, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	dijkstraStandart(graph, 1, 6);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(6);


	std::cout << std::endl << "Implementacja Boost:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 7, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	dijkstraBoost(graph, 1, 7);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(7);

	//Bellman-Ford standard

	std::cout << std::endl << std::endl << "Bellman-Ford: " << std::endl << "Wlasna implementacja:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 8, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	BellmanFordNormal(graph, 1, 8);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(8);


	std::cout << std::endl << "Implementacja Boost:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 9, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	BellmanFordBoost(graph, 1, 9);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(9);

	std::cout << std::endl << std::endl << "Johnson: " << std::endl << "Wlasna implementacja:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 10, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	JohnsonNormal(graph, 1, 10);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(10);


	std::cout << std::endl << "Implementacja Boost:";
	begin = high_resolution_clock::now();
	graph->standardGraph();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 11, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	std::cout << std::endl;
	JohnsonBoost(graph, 1, 11);
	std::cout << std::endl << "Czas obu operacji: " << graph->calcBothTime(11);

}
void debugTest()
{

	Graph* genGraph = new Graph(10, 100);
	std::shared_ptr<Graph> graph(genGraph);
	testing(graph);
}




void memoryTest()
{
	size_t k = 1000;
	for (size_t size = 11000;  size<= 12000; size=size+k)
	{ 
		
		std::cout << "Liczba wierzcholkow: "<< size << std::endl;
		Graph* genGraph = new Graph(size, 33);
		genGraph->standardGraph();
		std::cout << "Graf standardowy wygenerowany"<<std::endl;
		system("pause");
		genGraph->boostSimpleGraph();
		genGraph->freeGraphStandard();
		std::cout << "Graf adjency_matrix nieskierowany wygenerwoany" << std::endl;
		system("pause");
		genGraph->freeAll();
		genGraph->standardGraph();
		genGraph->boostWeightedGraph();
		genGraph->freeGraphStandard();
		std::cout << "Graf adjency_list nieskierowany wygenerwoany" << std::endl;
		system("pause");
		genGraph->freeAll();
		genGraph->standardGraph();
		genGraph->boostDirectedGraph();
		genGraph->freeGraphStandard();
		std::cout << "Graf adjency_list  skierowany wygenerowany" << std::endl;
		system("pause");
		genGraph->freeAll();
	}
}