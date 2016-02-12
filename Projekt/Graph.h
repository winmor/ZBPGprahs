#ifndef GRAPH_GENERATOR_H_
#define GRAPH_GENERATOR_H_

#include <limits.h>

#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/adjacency_list.hpp>
#include "baseGraph.h"

class Graph
{
protected:
	typedef boost::property<boost::edge_weight_t, base::weight> weightProperty;
public:
	typedef boost::adjacency_matrix<boost::undirectedS> boostNoWeightedGraph;
	typedef boost::adjacency_list <boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, weightProperty> boostWeightGraph;
	typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property, boost::property<boost::edge_weight_t, int, boost::property<boost::edge_weight2_t, int> > > boostDirectedJohnson;
	typedef std::pair<int, int> Edge;

		

	
protected:
	const size_t mSize;
	int mFill;
	double duration[3][12];

	base::graphMatrix matrixStandardGraph= NULL;
	base::weight minWeight;
	base::weight maxWeight;
	base::weight randomEdge();
	std::shared_ptr<boostNoWeightedGraph> matrixBoostSimpleGraph;
	std::shared_ptr<boostWeightGraph> matrixBoostWeightedGraph;
	std::shared_ptr<boostDirectedJohnson> matrixBoostJohnsonGraph;
	
	 

	
public:
	virtual base::graphMatrix standardGraph();
	std::shared_ptr<boostNoWeightedGraph> boostSimpleGraph();
	std::shared_ptr<boostWeightGraph> boostWeightedGraph();
	std::shared_ptr<boostDirectedJohnson> boostJohnson();
	boostNoWeightedGraph::vertex_descriptor boostInitVertex();
	Graph(size_t size, int fill);
	void print();
	const size_t size();
	const int fill();
	void setExpTime(int i, int j, double value);
	double calcBothTime(int j);
	double printTime(int i, int j);
	boostNoWeightedGraph::vertex_descriptor initVertex();
	virtual ~Graph();
	void freeGraphStandard();
	void freeGraphBoost();
	void freeAll();
	

};
#endif