#include "BeginExploration.h"
#include "Graph.h"
#include "DFSnormal.h"
#include "DFSboost.h"
#include "BFSnormal.h"
#include "BFSboost.h"
#include "Exploration.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <stdlib.h>

void experimentDepthFirst(const std::shared_ptr<Graph>& graph)
{
	using namespace std::chrono;

	//graf zwyk³y DFS
	std::cout << std::endl << "Depth First: " << std::endl << "Wlasna implementacja:";
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	graph->standardGraph();
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(0, 0, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
#ifdef DEBUG
	graph->print();
#endif
	//przeszukiwanie grafu zwyk³ego
	DFSnormal(graph,1,0);
	std::cout << std::endl << graph->printTime(1, 0);
	std::cout << std::endl << "Czas obu operacji: "<< graph->calcBothTime(0);

	std::cout << std::endl << std::endl << "Implementacja boost: ";
	//graf zwyk³y boost
	begin = high_resolution_clock::now();
	timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->boostSimpleGraph();
	graph->setExpTime(0, 1, timeSpan.count());
	std::cout << std::endl << "Czas tworzenie grafu: " << timeSpan.count();
	//przeszukiwanie zwyk³ego boost
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