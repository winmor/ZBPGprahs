
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

void DFSexploration(int sizeA, int sizeB)
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;
	
	size_t sizes[] = { sizeA,sizeB };
	probeCount  level100 = createGraphs(sizes, 2, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, 2, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, 2, numberProbes, 33);

	probes[0] = DFSduration(level100);
	probes[1] = DFSduration(level66);
	probes[2] = DFSduration(level33);

	printResults(sizes, 2, probes);
}
void BFSexploration(int sizeA, int sizeB)
{
	std::vector<probeDuration> probes(3);
	size_t numberProbes = 4;

	size_t sizes[] = { sizeA,sizeB };
	probeCount  level100 = createGraphs(sizes, 2, numberProbes, 100);
	probeCount  level66 = createGraphs(sizes, 2, numberProbes, 66);
	probeCount  level33 = createGraphs(sizes, 2, numberProbes, 33);

	probes[0] = BFSduration(level100);
	probes[1] = BFSduration(level66);
	probes[2] = BFSduration(level33);

	printResults(sizes, 2, probes);
}
void exploration()
{
	DFSexploration(3000, 4000);
	BFSexploration(3000, 4000);

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