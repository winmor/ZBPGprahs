#include "FloydWarshallBoost.h"
#include <iomanip>
#include <iostream>
#include <boost\multi_array.hpp>
#include <boost\graph\floyd_warshall_shortest.hpp>
#include <chrono>

void FloydWarshallBoost(std::shared_ptr<Graph> graph, int i, int j)
{
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();

	typedef boost::multi_array<base::weight, 2> array_type;

	array_type D(boost::extents[graph->size()][graph->size()]);
	boost::floyd_warshall_all_pairs_shortest_paths(*graph->boostWeightedGraph(), D);

	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());
#ifdef DEBUG
	std::cout << "       ";
	for (size_t k = 0; k < graph->size(); ++k) {
		std::cout << std::setw(5) << k;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < graph->size(); ++i) {
		std::cout << std::setw(3) << i << " -> ";
		for (size_t j = 0; j < graph->size(); ++j) {
			if (D[i][j] == (std::numeric_limits<int>::max)()) {
				std::cout << std::setw(5) << "x";
			}
			else {
				std::cout << std::setw(5) << D[i][j];
			}
		}
		std::cout << std::endl;
	}
#endif
}
