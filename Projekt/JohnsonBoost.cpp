#include "JohnsonBoost.h"

#include <boost/multi_array.hpp>
#include <boost/graph/johnson_all_pairs_shortest.hpp>
#include <boost/graph/graph_traits.hpp>

#include <boost/config.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <chrono>

void JohnsonBoost(std::shared_ptr<Graph> graph, int i, int j)
{
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	Graph::boostWeightGraph g = *graph->boostWeightedGraph();
	
	typedef boost::multi_array<base::weight, 2> array_type;
	array_type D(boost::extents[graph->size()][graph->size()]);


	johnson_all_pairs_shortest_paths(g, D);





	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());
#ifdef _DEBUG
	int V = num_vertices(g);
	std::cout << "       ";
	for (int k = 0; k < V; ++k)
		std::cout << std::setw(5) << k;
	std::cout << std::endl;
	for (int i = 0; i < V; ++i) {
		std::cout << std::setw(3) << i << " -> ";
		for (int j = 0; j < V; ++j) {
			if (D[i][j] == (std::numeric_limits<int>::max)())
				std::cout << std::setw(5) << "x";
			else
				std::cout << std::setw(5) << D[i][j];
		}
		std::cout << std::endl;
	}
#endif
}
