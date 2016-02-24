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

	typedef boost::adjacency_matrix<boost::undirectedS, boost::no_property, weightProperty> boostWeightedMatrix;

	typedef boost::adjacency_list <boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, weightProperty> boostWeightGraph;
	typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property, boost::property<boost::edge_weight_t, int, boost::property<boost::edge_weight2_t, int> > > boostDirected;
	typedef std::pair<int, int> Edge;

		

	
protected:
	const size_t mSize;
	int mFill;
	double duration[3][16];

	base::graphMatrix matrixStandardGraph= NULL;
	base::weight minWeight;
	base::weight maxWeight;
	base::weight randomEdge();
	std::shared_ptr<boostNoWeightedGraph> matrixBoostSimpleGraph;
	std::shared_ptr<boostWeightedMatrix> matrixBoostWeightedSimpleGraph;
	std::shared_ptr<boostWeightGraph> adjListBoostWeightedGraph;
	std::shared_ptr<boostDirected> adjListBoostDirectedGraph;
	
	 

	
public:
	virtual base::graphMatrix standardGraph();
	std::shared_ptr<boostNoWeightedGraph> boostSimpleGraph();
	std::shared_ptr<boostWeightGraph> boostWeightedGraph();


	std::shared_ptr<boostWeightedMatrix> boostWeightedMatrixSimpleGraph();

	std::shared_ptr<boostDirected> boostDirectedGraph();
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