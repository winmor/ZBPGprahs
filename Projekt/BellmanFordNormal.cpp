#include "BellmanFordNormal.h"
#include <chrono>
void BellmanFordNormal(std::shared_ptr<Graph> graph, int i, int j)
{
	base::graphMatrix G = graph->standardGraph();
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	std::vector<double> d;
	BellmanFord(G, 0, graph->size(), d);
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());
#ifdef _DEBUG
	if (d.empty())
		std::cout << "Wykryto ujemny cykl" << std::endl;
	else {
		for (int i = 0; i < d.size(); ++i)
			std::cout << 0 << " --> " << i << " : " << d[i] << std::endl;
	}
#endif
}

bool BellmanFord(base::graphMatrix G, unsigned int source, size_t n, std::vector<double>& d)
{
	//init
	d.clear();
	std::vector<double> p;

	for (unsigned int i = 0; i < n; i++)
	{
		d.push_back(INT_MAX);
		p.push_back(0);
	}
	d[source] = 0;
	//relaksacja
	for (unsigned int i = 1; i < n; ++i) {
		for (unsigned int u = 0; u < n; ++u) {
			for (unsigned int v = 0; v < n; ++v) {
				int edgeWeight = G[u][v];
				if (edgeWeight != base::withoutEdge) {
					if (d[u] + edgeWeight < d[v]) {
						d[v] = d[u] + edgeWeight;
						p[v] = u;
					}
				}
			}
		}
	}
	//czy sa ujemne cykle
	for (unsigned int u = 0; u < n; ++u) {
		for (unsigned int v = 0; v < n; ++v) {
			int edgeWeight = G[u][v];
			if (edgeWeight != base::withoutEdge) {
				if (d[u] + edgeWeight < d[v]) {
					d.clear();
					return false;
				}
			}
		}
	}
	return true;
}
