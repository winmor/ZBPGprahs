
#include "DijkstraBoost.h"
#include "Graph.h"
#include "boost\multi_array.hpp"
#include "boost\graph\dijkstra_shortest_paths.hpp"
#include "boost\graph\graph_traits.hpp"


using namespace boost;
void dijkstraBoost(std::shared_ptr<Graph> graph)
{
	Graph::boostWeightGraph g = *graph->boostWeightedGraph();
	typedef graph_traits<Graph::boostWeightGraph>::vertex_descriptor vertex_descriptor;
	std::vector<vertex_descriptor> parent(num_vertices(g));
	std::vector<int> distance(num_vertices(g));
	dijkstra_shortest_paths(g, graph->boostInitVertex(), predecessor_map(&parent[0]).distance_map(&distance[0]));

#ifdef DEBUG
	std::cout << odleglosci i rodzice : "<< std::endl;
		graph_traits<Graph::boostWeightGraph>::vertex_iterator vi, vend;
	for (tie(vi, vend) = vertices(g); vi != vend, vi++)
	{
		std::cout << "odleglosc(" << *vi << ") =" << distance[*vi] << ", ";
		std::cout << "rodzic(" << *vi << ") =" << parent[*vi] << ", ";
	}
	std::cout << std::endl;
#endif // DEBUG

}
