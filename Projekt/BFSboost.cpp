#include "BFSboost.h"
#include "Graph.h"
#include <boost\graph\breadth_first_search.hpp>
#include <chrono>
#ifdef _DEBUG
#include <iostream>
#endif
class BFSVisitor : public boost::default_bfs_visitor {
public:
	template<typename Vertex, typename Graph>
	void discover_vertex(Vertex u, const Graph & g) const {
#ifdef _DEBUG
		std::cout << u << " ";
#endif
	}

};

void BFSBoost(std::shared_ptr<Graph> graph, int i, int j)
{
	BFSVisitor vis;
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	boost::breadth_first_search(*(graph->boostSimpleGraph()), graph->initVertex(), boost::visitor(vis));
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());

}
