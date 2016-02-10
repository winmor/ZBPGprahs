#include "DFSnormal.h"
#include <chrono>
#include <algorithm>
#include <windows.h>
#include <stdio.h>
#include <psapi.h>
void depthFirstVisit(base::graphMatrix G, bool * Visited, int i, size_t n);

void depthFirst(base::graphMatrix G, bool *Visited, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		Visited[i] = 0;
	}
	for (size_t i = 0; i < n; i++) {
		if (Visited[i] == 0) {
			depthFirstVisit(G, Visited, i, n);
		}
	}
}
void depthFirstVisit(base::graphMatrix G, bool * Visited, int i, size_t n)
{
#ifdef _DEBUG
	std::cout << i << " ";
#endif
	Visited[i] = 1;
	for (size_t j = 0; j < n; j++)
	{
		if(G[i][j] != base::withoutEdge)
			if (Visited[j] == 0)
			{
				depthFirstVisit(G, Visited, j, n);
			}
	}
}

void DFSnormal(std::shared_ptr<Graph> graph, int i, int j)
{
	bool *Visited = new bool[graph->size()];
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	depthFirst(graph->standardGraph(), Visited, graph->size());
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());
}
