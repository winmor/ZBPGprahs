#include "JohnsonNormal.h"
#include "DijkstraNormal.h"
#include "BellmanFordNormal.h"

#include <iostream>
#include <iomanip>
#include <chrono>



bool johnson(base::graphMatrix G, unsigned int source, size_t n, std::vector<std::vector<double>>& d) {

	//init
	d.clear();
	std::vector<double> h;

	//tworzenie G2 przez dodanie nowego wierzcho³ka S z wagami 0 dla tego wierzcho³ka
	size_t size_G2 = n + 1;

	base::graphMatrix G2 = new base::weight*[size_G2];
	base::weight* s = new base::weight[size_G2];
	G2[0] = s;

	for (unsigned int i = 0; i < n; i++)
	{
		G2[i + 1] = new  base::weight[size_G2];
		for (unsigned int j = 0; j < n; j++)
		{
			G2[i + 1][j + 1] = G[i][j];
//wierzcho³ek S bez krawedzi
			G2[i + 1][0] = base::withoutEdge;
		}
	}
	//ujemne cykle
	if (!BellmanFord(G2, 0, size_G2, h));
		return false;

	//nieujemne wartosci krawedzi w grafie G
	for (unsigned int u = 0; u < n; u++)
	{
		for (unsigned int v = 0; v < n; v++)
		{
			int edgeWeight = G[u][v];
			if(edgeWeight!=base::withoutEdge){
			G[u][v] = G[u][v] + h[u + 1] - h[v + 1];; //+1 bo dodany wierzcho³ek z S do G2
			}
		}
	}
	//obliczanie wartosci macierzy d
	for (unsigned int u = 0; u < n; u++)
	{ 
		std::vector<double> k;
	d.push_back(k);
	dijkstra(G, u, n, d[u]);
	for (unsigned int v = 0; v < n; v++)
	{
		d[u][v] = d[u][v] + h[v + 1] - h[u + 1];
	}
	}
	return true;
}
void JohnsonNormal(std::shared_ptr<Graph> graph , int i, int j)
{
	base::graphMatrix G = graph->standardGraph();
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	std::vector<std::vector<double>> D;
	johnson(G, 0, graph->size(), D);
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());

#ifdef _DEBUG
	int V = graph->size();
	std::cout << "       ";
	for (int k = 0; k < V; ++k)
		std::cout << std::setw(5) << k;
	std::cout << std::endl;
	for (int i = 0; i < V; ++i) {
		std::cout << std::setw(3) << i << " -> ";
		for (int j = 0; j < V; ++j) {
			if (D[i][j] == (std::numeric_limits<int>::max)())
				std::cout << std::setw(5) << "x";
			else
				std::cout << std::setw(5) << D[i][j];
		}
		std::cout << std::endl;
	}
#endif
}
