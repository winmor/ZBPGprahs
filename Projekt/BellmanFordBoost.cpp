#include "BellmanFordBoost.h"

#include <memory>
#ifdef DEBUG
#include <iostream>
#endif
#include "boost\multi_array.hpp"
#include "boost\graph\bellman_ford_shortest_paths.hpp"
#include "boost\graph\graph_traits.hpp"
#include <chrono>

void BellmanFordBoost(std::shared_ptr<Graph> graph, int i, int j)
{
	Graph::boostWeightGraph g = *graph->boostWeightedGraph();
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	typedef boost::graph_traits<Graph::boostWeightGraph>::vertex_descriptor vertex_descriptor;
	std::vector<vertex_descriptor> parent(num_vertices(g));
	std::vector<int> distance(num_vertices(g), base::withoutEdge);
	distance[0] = 0; // initial vertex
	bellman_ford_shortest_paths(g, boost::predecessor_map(&parent[0]).distance_map(&distance[0]));
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());
//#ifdef DEBUG
//	std::cout << "odleg³oœci i rodzice:" << std::endl;
//	graph_traits<graph_generator::BoostWeightedGraph>::vertex_iterator vi, vend;
//	for (tie(vi, vend) = vertices(g); vi != vend; ++vi) {
//		std::cout << "distance(" << *vi << ") = " << distance[*vi] << ", ";
//		std::cout << "parent(" << *vi << ") = " << parent[*vi] << std::endl;
//	}
//	std::cout << std::endl;
//#endif
}
