
#include "DijkstraNormal.h"
#include <chrono>


bool dijkstra(base::graphMatrix G, unsigned int source, size_t n, std::vector<double>& d) {

	int u;
	int minDinQ = INT_MAX;

	std::vector<double> p;
	std::set<int> S;
	std::set<int> Q;

	//init
	for (unsigned int i = 0; i < n; i++)
	{
		d.push_back(INT_MAX);
		p.push_back(0);
		Q.insert(i);
	}
	d[source] = 0;

	while (!Q.empty())
	{
		minDinQ = INT_MAX;
		for (const int &q : Q)
		{
			int actualDval = d[q];
			if (minDinQ == INT_MAX)
			{
				minDinQ = actualDval;
				u = q; //wierzcho³ek z Q o min d;
			}
			else if (actualDval < minDinQ)
			{
				minDinQ = actualDval;
				u = q;
			}
		}
		// S:=S+{u};
		if (minDinQ != INT_MAX)
		{
			Q.erase(u);
			S.insert(u);
		}

		for (unsigned int v = 0; v < n; v++)
		{
			int edgeWeight = G[u][v];
			if (edgeWeight != base::withoutEdge)
			{
				if (d[u] + edgeWeight < d[v])
				{
					d[v] = d[u] + edgeWeight;
					p[v] = u;
				}
			}
		}
		if (minDinQ != INT_MAX)
		{
			Q.erase(u);
			S.insert(u);
		}

		
	}
	return true;
}

void dijkstraStandart(std::shared_ptr<Graph> graph, int i, int j)
	{
	base::graphMatrix G = graph->standardGraph();
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	std::vector<double> d;
	dijkstra(G, 0, graph -> size(), d);
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());



#ifdef _DEBUG
	for (int i = 0; i < d.size(); ++i) {
		std::cout << 0 << " --> " << i << " : " << d[i] << std::endl;
	}
#endif
}




