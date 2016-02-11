
#include "Exploration.h"
#include "DataExp.h"
#include <iomanip> 
GraphVector constructGraphs(size_t numberProbes, int size, int fill);
typedef std::map<unsigned int, Duration> probeDuration;

probeDuration DFSduration(probeCount graphs)
{
	probeDuration result;
	for (probeCount::iterator it = graphs.begin(); it != graphs.end(); it++)
	{
		result[it->first] = DFSexperiment(it->second);
	}
	return result;
}
probeDuration BFSduration(probeCount graphs)
{
	probeDuration result;
	for (probeCount::iterator it = graphs.begin(); it != graphs.end(); it++)
	{
		result[it->first] = BFSexperiment(it->second);
	}
	return result;
}
probeDuration floydWarshallDuration(probeCount graphs)
{
	probeDuration result;
	for (probeCount::iterator it = graphs.begin(); it != graphs.end(); it++)
	{
		result[it->first] = floydWarshallExperiment(it->second);
	}
	return result;
}

probeDuration dijkstraDuration(probeCount graphs)
{
	probeDuration result;
	for (probeCount::iterator it = graphs.begin(); it != graphs.end(); it++)
	{
		result[it->first] = dijkstraExperiment(it->second);
	}
	return result;
}
probeDuration bellmanFordDuration(probeCount graphs)
{
	probeDuration result;
	for (probeCount::iterator it = graphs.begin(); it != graphs.end(); it++)
	{
		result[it->first] = bellmanFordExperiment(it->second);
	}
	return result;
}
probeDuration johnsonDuration(probeCount graphs)
{
	probeDuration result;
	for (probeCount::iterator it = graphs.begin(); it != graphs.end(); it++)
	{
		result[it->first] = johnsonExperiment(it->second);
	}
	return result;
}





void printResults(size_t sizes[], int size, std::vector<probeDuration> probes)
{
	
	for (size_t i = 0; i < size; i++)
	{
		int k = 0;
		std::cout << std::endl << "###########  Liczba wierzcholkow: " << sizes[i] << std::endl << std::endl;
		std::cout << "Tworzenie stand\tTworzenie boost\tSzukanie stand\tSzukanie boost\tSuma stand\tSuma boost\t" << std::endl << std::endl;
		for (std::vector<probeDuration>::iterator it = probes.begin(); it != probes.end(); it++)
		{
			if (k == 0)
			{
				std::cout <<"100% wypelnienia" << std::endl;
				
			}
			if (k == 1)
			{
				std::cout << "66% wypelnienia" << std::endl;

			}
			if (k == 2)
			{
				std::cout << "33% wypelnienia" << std::endl;

			}
				
				std::cout << std::setprecision(4) << (*it)[sizes[i]].createStandardDuration << "\t\t" << (*it)[sizes[i]].createBoostDuration << "\t\t" << (*it)[sizes[i]].searchStadndardDuration << "\t\t" << (*it)[sizes[i]].searchBoostDuration << "\t\t" << (*it)[sizes[i]].standardAllDuration << "\t\t" << (*it)[sizes[i]].boostAllDuration << "\t\t" << std::endl<< std::endl;
				k++;
		}
	}
}

void DFSexploration(size_t sizes[])
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	size_t length = sizeof(sizes) / sizeof(size_t);
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = DFSduration(level100);
	probes[1] = DFSduration(level66);
	probes[2] = DFSduration(level33);

	printResults(sizes, length, probes);
}
void BFSexploration(size_t sizes[])
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	size_t length = sizeof(sizes) / sizeof(size_t);
	
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = BFSduration(level100);
	probes[1] = BFSduration(level66);
	probes[2] = BFSduration(level33);

	printResults(sizes, length, probes);
}

void FloydWarshallExploration(size_t sizes[])
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;

	size_t length = sizeof(sizes) / sizeof(size_t);
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = floydWarshallDuration(level100);
	probes[1] = floydWarshallDuration(level66);
	probes[2] = floydWarshallDuration(level33);

	printResults(sizes, length, probes);
}


void Dijkstra(size_t sizes[])
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;

	size_t length = sizeof(sizes) / sizeof(size_t);
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = dijkstraDuration(level100);
	probes[1] = dijkstraDuration(level66);
	probes[2] = dijkstraDuration(level33);

	printResults(sizes, length, probes);
}
void BellmanFordExploration(size_t sizes[])
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	size_t length = sizeof(sizes) / sizeof(size_t);
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = bellmanFordDuration(level100);
	probes[1] = bellmanFordDuration(level66);
	probes[2] = bellmanFordDuration(level33);

	printResults(sizes, length, probes);
}
void JohnsonExploration(size_t sizes[])
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	size_t length = sizeof(sizes) / sizeof(size_t);
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = johnsonDuration(level100);
	probes[1] = johnsonDuration(level66);
	probes[2] = johnsonDuration(level33);

	printResults(sizes, length, probes);
}
void exploration()
{
	//size_t sizesDFSBFS[] = { 3000,4000 };
	//std::cout << "DFS" << std::endl;
	//DFSexploration(sizesDFSBFS);
	//std::cout << "BFS" << std::endl;
	//BFSexploration(sizesDFSBFS);
	//size_t sizesFW[] = { 300,400 };
	//std::cout << "FW" << std::endl;
	//FloydWarshallExploration(sizesFW);
	//size_t sizesDjikstra[] = { 250,1250 };
	//std::cout << "Dijkstra" << std::endl;
	//Dijkstra(sizesDjikstra);
	//size_t sizesBF[] = { 250,1250 };
	//std::cout << "Bellman Ford" << std::endl;
	//BellmanFordExploration(sizesBF);
	 size_t sizesJohnson[] = { 250,450 };
	std::cout << "Johnson" << std::endl;
	JohnsonExploration(sizesJohnson)


}

probeCount createGraphs(size_t sizes[], int length, size_t numberProbes, unsigned short fill)
{
	probeCount graphs;
	for (int i = 0; i < length; i++)
	{
		graphs[sizes[i]] = constructGraphs(numberProbes, sizes[i], fill);
	}
	return graphs;
}

GraphVector constructGraphs(size_t numberProbes, int size, int fill)
{
	GraphVector graphs(numberProbes);
	for (size_t i = 0; i < numberProbes; i++)
	{
		Graph* generate = new Graph(size, fill);
		graphs[i] = std::shared_ptr<Graph>(generate);

	}
	return graphs;
}