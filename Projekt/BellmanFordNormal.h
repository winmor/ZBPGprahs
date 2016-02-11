#include "Graph.h"

void BellmanFordNormal(std::shared_ptr<Graph> graph, int i, int j);
bool BellmanFord(base::graphMatrix G, unsigned int source, size_t n, std::vector<double>& d);