#include <chrono>
#include <queue>
#include "BFSnormal.h"

void breadthFirst(base::graphMatrix Graph, bool *Visited, size_t n)
{
	std::queue<int> kolejka;
	for (size_t i = 0; i < n; i++)
	{
		Visited[i] = 0;
	}
	kolejka.push(0);

	while (!kolejka.empty())
	{
		int s = kolejka.front();
		kolejka.pop();
#ifdef _DEBUG
		std::cout << s << " ";
#endif
		Visited[s] = 1;
		for (size_t i = 0; i < n; i++)
		{
			if (Graph[s][i] != base::withoutEdge) {
				if (Visited[i] == false)
				{
					Visited[i] = true;
					kolejka.push(i);
				}
			}
		}
	}
}

void BFSstandard(std::shared_ptr<Graph> graph, int i, int j)
{
	bool *Visited = new bool[graph->size()];
	using namespace std::chrono;
	high_resolution_clock::time_point begin = high_resolution_clock::now();
	breadthFirst(graph->standardGraph(), Visited, graph->size());
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
	graph->setExpTime(i, j, timeSpan.count());
	

}
