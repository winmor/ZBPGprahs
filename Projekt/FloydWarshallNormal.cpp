#include "FloydWarshallNormal.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <iomanip>
#include <chrono>
void floydWarshall(base::graphMatrix G, size_t n)
{
	for (size_t k = 0; k < n; k++) {
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
}


void FloydWarshallNormal(std::shared_ptr<Graph> graph, int i, int j)
{
	base::graphMatrix matrixStandardGraph = graph->standardGraph();
	using namespace std::chrono;
	base::graphMatrix D = new base::weight*[graph->size()];
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	for (size_t i = 0; i < graph->size(); i++)
	{
		D[i] = new base::weight[graph->size()];
		std::copy(matrixStandardGraph[i], matrixStandardGraph[i] + graph->size(), D[i]);

	}
	floydWarshall(D, graph->size());
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());

#ifdef _DEBUG
	std::cout << "       ";
	for (size_t k = 0; k < graph->size(); ++k) {
		std::cout << std::setw(5) << k;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < graph->size(); ++i) {
		std::cout << std::setw(3) << i << " -> ";
		for (size_t j = 0; j < graph->size(); ++j) {
			if (D[i][j] == base::withoutEdge) {
				std::cout << std::setw(5) << "x";
			}
			else {
				std::cout << std::setw(5) << D[i][j];
			}
		}
		std::cout << std::endl;
	}
#endif

	for (size_t i = 0; i < graph->size(); i++) {
		delete[] D[i];
	}
	delete[] D;
}
