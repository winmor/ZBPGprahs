#include "FloydWarshallBoost.h"
#include <iomanip>
#include <iostream>
#include <boost\multi_array.hpp>
#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/exterior_property.hpp>
#include <boost\graph\floyd_warshall_shortest.hpp>
#include <chrono>

void FloydWarshallBoostAdjMatrix(std::shared_ptr<Graph> graph, int i, int j)
{
	using namespace std::chrono;

	Graph::boostWeightedMatrix g = *graph->boostWeightedMatrixSimpleGraph();

	typedef boost::property_map<Graph::boostWeightedMatrix, boost::edge_weight_t>::type WeightMap;
	typedef boost::exterior_vertex_property<Graph::boostWeightedMatrix, base::weight> DistanceProperty;
	typedef DistanceProperty::matrix_type DistanceMatrix;
	typedef DistanceProperty::matrix_map_type DistanceMatrixMap;
	WeightMap weight_pmap = boost::get(boost::edge_weight, g);
	DistanceMatrix distances(num_vertices(g));
	DistanceMatrixMap dm(distances, g);

	high_resolution_clock::time_point begin = high_resolution_clock::now();
	boost::floyd_warshall_all_pairs_shortest_paths(g, dm,
		boost::weight_map(weight_pmap));

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
			if (distances[i][j] == (std::numeric_limits<int>::max)()) {
				std::cout << std::setw(5) << "x";
			}
			else {
				std::cout << std::setw(5) << distances[i][j];
			}
		}
		std::cout << std::endl;
	}
#endif
}
