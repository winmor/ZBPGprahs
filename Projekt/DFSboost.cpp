#include "DFSboost.h"


#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/depth_first_search.hpp>
#include "Graph.h"
#include <chrono>
#ifdef _DEBUG
#include <iostream>
#endif
class DFSVisitor : public boost::default_dfs_visitor {
public:
	template<typename Vertex, typename Graph>
	void discover_vertex(Vertex u, const Graph & g) const {
#ifdef _DEBUG
	std::cout << u << " ";
#endif
	}
};

void DFSBoost(std::shared_ptr<Graph> graph, int i, int j)
{
	DFSVisitor vis;
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();


	boost::depth_first_search(*graph->boostSimpleGraph(), boost::visitor(vis));


	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());
	
}
