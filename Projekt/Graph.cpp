
#include "Graph.h"




base::weight Graph::randomEdge()
{
	bool connected = (rand() % 100) < mFill;

	return connected ? (1 + rand() % 9999) : base::withoutEdge;
	//if (connected)
	//{
	//	return 1 + rand() % 9;
	//}
	//else
	//{
	//	return base::withoutEdge;
	//}
}

base::graphMatrix Graph::standardGraph()
{
	if (matrixStandardGraph == NULL)
	{
		matrixStandardGraph = new base::weight*[mSize];
		for (size_t i = 0; i < mSize; i++)
		{
			matrixStandardGraph[i] = new base::weight[mSize];
			std::fill(matrixStandardGraph[i], matrixStandardGraph[i] + mSize, base::withoutEdge);
		}
		for (size_t i = 0; i < mSize; i++)
		{
			matrixStandardGraph[i][i] = 0;
			for (size_t j = 0; j < i; j++)
			{ 
				matrixStandardGraph[i][j] = matrixStandardGraph[j][i] = randomEdge();
			}
		}
	}
	return matrixStandardGraph;
}

std::shared_ptr<Graph::boostNoWeightedGraph> Graph::boostSimpleGraph()
{
	if (!matrixBoostSimpleGraph)
	{
		Graph::boostNoWeightedGraph* p =  new boostNoWeightedGraph(mSize);
		matrixBoostSimpleGraph = std::shared_ptr<Graph::boostNoWeightedGraph>(p);
		for (size_t i = 0; i < mSize; i++) {
			for (size_t j = 0; j < i; j++)
			{
				if (matrixStandardGraph[i][j] != base::withoutEdge)
				{
					boost::add_edge(i, j, *matrixBoostSimpleGraph);
				}
			}
		}
	}
	return matrixBoostSimpleGraph;
}
std::shared_ptr<Graph::boostWeightedMatrix> Graph::boostWeightedMatrixSimpleGraph()
{
	if (!matrixBoostWeightedSimpleGraph)
	{
		Graph::boostWeightedMatrix* p = new boostWeightedMatrix(mSize);
		matrixBoostWeightedSimpleGraph = std::shared_ptr<boostWeightedMatrix>(p);
		for (size_t i = 0; i < mSize; i++) {
			for (size_t j = 0; j < i; j++)
			{
				if (matrixStandardGraph[i][j] != base::withoutEdge)
				{
					boost::add_edge(i, j, matrixStandardGraph[i][j], *matrixBoostWeightedSimpleGraph);
				}
			}
		}
	}
	return matrixBoostWeightedSimpleGraph;
}

std::shared_ptr<Graph::boostWeightGraph> Graph::boostWeightedGraph()
{
	
	if (!adjListBoostWeightedGraph)
	{
		Graph::boostWeightGraph* p = new boostWeightGraph();
		adjListBoostWeightedGraph = std::shared_ptr<boostWeightGraph>(p);
		boost::graph_traits<boostWeightGraph>::vertex_descriptor u, v;
	
		for (size_t i = 0; i < mSize; i++) {
			for (size_t j = 0; j < i;j++) {
				if (matrixStandardGraph[i][j] != base::withoutEdge)
				{
					u = boost::vertex(i, *adjListBoostWeightedGraph);
					v = boost::vertex(j, *adjListBoostWeightedGraph);
					boost::add_edge(u, v, matrixStandardGraph[i][j], *adjListBoostWeightedGraph);
				}
			}
		}
	}
	return adjListBoostWeightedGraph;
}








std::shared_ptr<Graph::boostDirected> Graph::boostDirectedGraph()
{
	if (!adjListBoostDirectedGraph)
	{
		Graph::boostDirected* p = new boostDirected();
		adjListBoostDirectedGraph = std::shared_ptr<boostDirected>(p);
		boost::graph_traits<boostDirected>::vertex_descriptor u, v;
		for (size_t i = 0; i < mSize; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (matrixStandardGraph[i][j] != base::withoutEdge)
				{
					u = boost::vertex(i, *adjListBoostDirectedGraph);
					v = boost::vertex(j, *adjListBoostDirectedGraph);
					boost::add_edge(u, v, matrixStandardGraph[i][j], *adjListBoostDirectedGraph);
				}
			}
		}

	}
	return adjListBoostDirectedGraph;
}

Graph::boostNoWeightedGraph::vertex_descriptor Graph::boostInitVertex()
{
	return boost::vertex(0, *matrixBoostSimpleGraph);
}

Graph::Graph(size_t size, int fill): mSize(size), mFill(fill)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 12; j++)
		{ 
			duration[i][j] = 0;
		}
	}
}

void Graph::print()
{
	for (size_t i = 0; i < mSize; i++) {
		for (size_t j = 0; j < mSize; j++)
		{
			if (matrixStandardGraph[i][j] == base::withoutEdge)
			{
				std::cout << "-1" << " ";
			}
			else
			{
				std::cout << matrixStandardGraph[i][j] << " ";
			}

		}
		std::cout << std::endl;
	}
}

const size_t Graph::size()
{
	return mSize;
}

const int Graph::fill()
{
	return mFill;
}

void Graph::setExpTime(int i, int j, double value)
{
	duration[i][j] = value;
}

double Graph::calcBothTime(int j)
{
	for (int i = 0; i < 2; i++)
		duration[2][j] += duration[i][j];
	return duration[2][j];
}

double Graph::printTime(int i, int j)
{
	return duration[i][j];
}

Graph::boostNoWeightedGraph::vertex_descriptor Graph::initVertex()
{
	return boost::vertex(0, *matrixBoostSimpleGraph);
}

Graph::~Graph()
{
	freeGraphStandard();
	freeGraphBoost();
}

void Graph::freeGraphStandard()
{
	if (matrixStandardGraph != NULL)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			delete[] matrixStandardGraph[i];
		}
		delete[] matrixStandardGraph;
		matrixStandardGraph = NULL;
	}
}

void Graph::freeGraphBoost()
{
	matrixBoostSimpleGraph.reset();
	adjListBoostWeightedGraph.reset();
	adjListBoostDirectedGraph.reset();
	matrixBoostWeightedSimpleGraph.reset();
}

void Graph::freeAll()
{
	if (matrixStandardGraph != NULL)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			delete[] matrixStandardGraph[i];
		}
		delete[] matrixStandardGraph;
		matrixStandardGraph = NULL;
	}
	freeGraphBoost();
}












