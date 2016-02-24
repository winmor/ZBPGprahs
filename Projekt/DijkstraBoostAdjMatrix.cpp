
#include "DijkstraBoostAdjMatrix.h"

#include "boost\graph\dijkstra_shortest_paths.hpp"
#include "boost\graph\graph_traits.hpp"
#include <chrono>


using namespace boost;
void dijkstraBoostAdjMatrix(std::shared_ptr<Graph> graph, int i, int j)
{
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();

	Graph::boostWeightedMatrix g = *graph->boostWeightedMatrixSimpleGraph();

	typedef graph_traits<Graph::boostWeightedMatrix>::vertex_descriptor vertex_descriptor;
	std::vector<vertex_descriptor> parent(num_vertices(g));
	std::vector<int> distance(num_vertices(g));

	dijkstra_shortest_paths(g, graph->boostInitVertex(), predecessor_map(&parent[0]).distance_map(&distance[0]));
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);

	graph->setExpTime(i, j, timeSpan.count());

#ifdef _DEBUG
	std::cout << "odleglosci i rodzice : " << std::endl;
	graph_traits<Graph::boostWeightGraph>::vertex_iterator vi, vend;
	for (tie(vi, vend) = vertices(g); vi != vend; ++vi)
	{
		std::cout << "odleglosc(" << *vi << ") =" << distance[*vi] << ", ";
		std::cout << "rodzic(" << *vi << ") =" << parent[*vi] << std::endl;
	}
	std::cout << std::endl;
#endif // DEBUG

}

