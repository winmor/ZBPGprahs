
#include "Exploration.h"
#include "DataExp.h"
#include <iomanip> 
GraphVector constructGraphs(unsigned int numberProbes, int size, int fill);
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

void DFSexploration(size_t sizes[], size_t length)
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = DFSduration(level100);
	probes[1] = DFSduration(level66);
	probes[2] = DFSduration(level33);

	printResults(sizes, length, probes);
}
void BFSexploration(size_t sizes[], size_t length)
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	
	
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = BFSduration(level100);
	probes[1] = BFSduration(level66);
	probes[2] = BFSduration(level33);

	printResults(sizes, length, probes);
}

void FloydWarshallExploration(size_t sizes[], size_t length)
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;

	
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = floydWarshallDuration(level100);
	probes[1] = floydWarshallDuration(level66);
	probes[2] = floydWarshallDuration(level33);

	printResults(sizes, length, probes);
}


void Dijkstra(size_t sizes[], size_t length)
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;

	
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = dijkstraDuration(level100);
	probes[1] = dijkstraDuration(level66);
	probes[2] = dijkstraDuration(level33);

	printResults(sizes, length, probes);
}
void BellmanFordExploration(size_t sizes[], size_t length)
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	
	
	probeCount  level100 = createGraphs(sizes, length, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, length, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, length, numberProbes, 33);

	probes[0] = bellmanFordDuration(level100);
	probes[1] = bellmanFordDuration(level66);
	probes[2] = bellmanFordDuration(level33);

	printResults(sizes, length, probes);
}
void JohnsonExploration(size_t sizes[], size_t length)
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	
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
	size_t sizesDFSBFS[] = {2000, 4000,6000, 8000, 10000 };
	size_t lengthDFSBFS = sizeof(sizesDFSBFS) / sizeof(size_t);
	std::cout << "DFS" << std::endl;
	DFSexploration(sizesDFSBFS, lengthDFSBFS);
	std::cout << "BFS" << std::endl;
	BFSexploration(sizesDFSBFS, lengthDFSBFS);
	size_t sizesFW[] = { 100,200,300,400,500 };
	size_t lengthFW = sizeof(sizesFW) / sizeof(size_t);
	std::cout << "FW" << std::endl;
	FloydWarshallExploration(sizesFW, lengthFW);
	size_t sizesDjikstra[] = { 200,400,600,800,1000 };
	size_t lengthDj = sizeof(sizesDjikstra) / sizeof(size_t);
	std::cout << "Dijkstra" << std::endl;
	Dijkstra(sizesDjikstra, lengthDj);
	size_t sizesBF[] = { 200,400,600,800,1000 };
	size_t lengthBF = sizeof(sizesBF) / sizeof(size_t);
	std::cout << "Bellman Ford" << std::endl;
	BellmanFordExploration(sizesBF, lengthBF);
	 size_t sizesJohnson[] = { 100,200,300,400,500};
	 size_t lengthSJ = sizeof(sizesJohnson) / sizeof(size_t);
	std::cout << "Johnson" << std::endl;
	JohnsonExploration(sizesJohnson,lengthSJ);


}

probeCount createGraphs(size_t sizes[], size_t length, size_t numberProbes, unsigned short fill)
{
	probeCount graphs;
	for (int i = 0; i < length; i++)
	{
		graphs[sizes[i]] = constructGraphs(numberProbes, sizes[i], fill);
	}
	return graphs;
}

GraphVector constructGraphs(unsigned int numberProbes, int size, int fill)
{
	GraphVector graphs(numberProbes);
	for (size_t i = 0; i < numberProbes; i++)
	{
		Graph* generate = new Graph(size, fill);
		graphs[i] = std::shared_ptr<Graph>(generate);

	}
	return graphs;
}