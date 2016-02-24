
#include "DataExp.h"
#include <chrono>
#include "DFSnormal.h"
#include "DFSboost.h"
#include "BFSnormal.h"
#include "BFSboost.h"
#include "FloydWarshallNormal.h"
#include "FloydWarshallBoost.h"
#include "FloydWarshallBoostAdjMatrix.h"
#include "DijkstraNormal.h"
#include "DijkstraBoost.h"
#include "DijkstraBoostAdjMatrix.h"
#include "BellmanFordNormal.h"
#include "BellmanFordBoost.h"
#include "JohnsonBoost.h"
#include "JohnsonBoostAdjMatrix.h"
#include "JohnsonNormal.h"
Duration DFSexperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration=0.0;
	result.createBoostDuration=0.0;
	result.createBoostDurationMatrixAdj = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDurationMatrix=0.0;
	result.searchBoostDurationAdjList = 0.0;
	result.standardAllDuration=0.0;
	result.boostAllDurationAdjList=0.0;
	result.boostAllDurationMatrix = 0.0;
	using namespace std::chrono;
	high_resolution_clock::time_point begin;
	duration<double> timeSpan;
	for (unsigned int i = 0; i < graphs.size(); i++)
	{
		
		graphs[i]->freeAll();
		begin = high_resolution_clock::now();
		graphs[i]->standardGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		
		result.createStandardDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 0, timeSpan.count());
		DFSnormal(graphs[i], 1, 0);
		result.searchStadndardDuration += graphs[i]->printTime(1, 0);
			graphs[i]->calcBothTime(0);
		result.standardAllDuration += graphs[i]->printTime(2, 0);


		begin = high_resolution_clock::now();
		graphs[i]->boostSimpleGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 1, timeSpan.count());
		DFSBoost(graphs[i], 1, 1);
		result.searchBoostDurationMatrix += graphs[i]->printTime(1, 1);
		result.boostAllDurationMatrix += graphs[i]->calcBothTime(1);


	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());
	result.createStandardDuration=result.createStandardDuration / static_cast<double>(graphs.size());
	result.searchBoostDurationMatrix = result.searchBoostDurationMatrix / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDurationMatrix = result.boostAllDurationMatrix / static_cast<double>(graphs.size());
	return result;
}
//
Duration BFSexperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.createBoostDurationMatrixAdj = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDurationMatrix = 0.0;
	result.searchBoostDurationAdjList = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDurationAdjList = 0.0;
	result.boostAllDurationMatrix = 0.0;
	using namespace std::chrono;
	high_resolution_clock::time_point begin;
	duration<double> timeSpan;
	for (unsigned int i = 0; i < graphs.size(); i++)
	{

		graphs[i]->freeAll();
		begin = high_resolution_clock::now();
		graphs[i]->standardGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createStandardDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 2, timeSpan.count());
		BFSstandard(graphs[i], 1, 2);
		result.searchStadndardDuration += graphs[i]->printTime(1, 2);
		graphs[i]->calcBothTime(2);
		result.standardAllDuration += graphs[i]->printTime(2, 2);


		begin = high_resolution_clock::now();
		graphs[i]->boostSimpleGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 3, timeSpan.count());
		BFSBoost(graphs[i], 1, 3);
		result.searchBoostDurationMatrix += graphs[i]->printTime(1, 3);
		result.boostAllDurationMatrix += graphs[i]->calcBothTime(3);


	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.searchBoostDurationMatrix = result.searchBoostDurationMatrix / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDurationMatrix = result.boostAllDurationMatrix / static_cast<double>(graphs.size());
	return result;
}


Duration floydWarshallExperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.createBoostDurationMatrixAdj = 0.0;
	result.searchStadndardDuration = 0;
	result.searchBoostDurationAdjList = 0.0;
	result.searchBoostDurationMatrix = 0.0;
	std::cout << "[]";
	
	result.standardAllDuration = 0.0;
	result.boostAllDurationAdjList = 0.0;
	result.boostAllDurationMatrix = 0.0;
	using namespace std::chrono;
	high_resolution_clock::time_point begin;
	duration<double> timeSpan;
	for (unsigned int i = 0; i < graphs.size(); i++)
	{

		graphs[i]->freeAll();
		begin = high_resolution_clock::now();
		graphs[i]->standardGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createStandardDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 4, timeSpan.count());
		FloydWarshallNormal(graphs[i], 1, 4);
		
		result.searchStadndardDuration += graphs[i]->printTime(1, 4);
		graphs[i]->calcBothTime(4);
		result.standardAllDuration += graphs[i]->printTime(2, 4);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 5, timeSpan.count());
		FloydWarshallBoost(graphs[i], 1, 5);
		result.searchBoostDurationAdjList += graphs[i]->printTime(1, 5);
		result.boostAllDurationAdjList += graphs[i]->calcBothTime(5);
		//dla reprezentacji matrixadj

		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedMatrixSimpleGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDurationMatrixAdj += timeSpan.count();
		graphs[i]->setExpTime(0, 6, timeSpan.count());
		FloydWarshallBoostAdjMatrix(graphs[i], 1, 6);
		result.searchBoostDurationMatrix += graphs[i]->printTime(1, 6);
		result.boostAllDurationMatrix += graphs[i]->calcBothTime(6);

		graphs[i]->freeAll();
	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());;
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.createBoostDurationMatrixAdj= result.createBoostDurationMatrixAdj / static_cast<double>(graphs.size());
	result.searchBoostDurationAdjList = result.searchBoostDurationAdjList / static_cast<double>(graphs.size());
	result.searchBoostDurationMatrix = result.searchBoostDurationMatrix / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDurationAdjList = result.boostAllDurationAdjList / static_cast<double>(graphs.size());
	result.boostAllDurationMatrix = result.boostAllDurationMatrix / static_cast<double>(graphs.size());
	return result;
}
//
Duration dijkstraExperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.createBoostDurationMatrixAdj = 0.0;
	result.searchStadndardDuration = 0;

	std::cout << "[]";
	result.searchBoostDurationAdjList = 0.0;
	result.searchBoostDurationMatrix = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDurationAdjList = 0.0;
	result.boostAllDurationMatrix = 0.0;
	using namespace std::chrono;
	high_resolution_clock::time_point begin;
	duration<double> timeSpan;
	for (unsigned int i = 0; i < graphs.size(); i++)
	{

		graphs[i]->freeAll();
		begin = high_resolution_clock::now();
		graphs[i]->standardGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createStandardDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 7, timeSpan.count());
		dijkstraStandart(graphs[i], 1, 7);

		result.searchStadndardDuration += graphs[i]->printTime(1, 7);
		graphs[i]->calcBothTime(7);
		result.standardAllDuration += graphs[i]->printTime(2, 7);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 8, timeSpan.count());
		dijkstraBoost(graphs[i], 1, 8);
		result.searchBoostDurationAdjList += graphs[i]->printTime(1, 8);
		result.boostAllDurationAdjList += graphs[i]->calcBothTime(8);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedMatrixSimpleGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDurationMatrixAdj += timeSpan.count();
		graphs[i]->setExpTime(0, 9, timeSpan.count());
		dijkstraBoostAdjMatrix(graphs[i], 1, 9);
		result.searchBoostDurationMatrix += graphs[i]->printTime(1, 9);
		result.boostAllDurationMatrix += graphs[i]->calcBothTime(9);

		graphs[i]->freeAll();

	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());;
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.createBoostDurationMatrixAdj = result.createBoostDurationMatrixAdj / static_cast<double>(graphs.size());
	result.searchBoostDurationAdjList = result.searchBoostDurationAdjList / static_cast<double>(graphs.size());
	result.searchBoostDurationMatrix = result.searchBoostDurationMatrix / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDurationAdjList = result.boostAllDurationAdjList / static_cast<double>(graphs.size());
	result.boostAllDurationMatrix = result.boostAllDurationMatrix / static_cast<double>(graphs.size());
	return result;
}
Duration bellmanFordExperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.createBoostDurationMatrixAdj = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDurationAdjList = 0.0;
	result.searchBoostDurationMatrix = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDurationAdjList = 0.0;
	result.boostAllDurationMatrix = 0.0;
	using namespace std::chrono;
	high_resolution_clock::time_point begin;
	duration<double> timeSpan;
	for (unsigned int i = 0; i < graphs.size(); i++)
	{

		graphs[i]->freeAll();
		begin = high_resolution_clock::now();
		graphs[i]->standardGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createStandardDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 10, timeSpan.count());
		BellmanFordNormal(graphs[i], 1, 10);

		result.searchStadndardDuration += graphs[i]->printTime(1, 10);
		graphs[i]->calcBothTime(10);
		result.standardAllDuration += graphs[i]->printTime(2, 10);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 11, timeSpan.count());
		BellmanFordBoost(graphs[i], 1, 11);
		result.searchBoostDurationAdjList += graphs[i]->printTime(1, 11);
		result.boostAllDurationAdjList += graphs[i]->calcBothTime(11);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedMatrixSimpleGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDurationMatrixAdj += timeSpan.count();
		graphs[i]->setExpTime(0, 12, timeSpan.count());
		BellmanFordBoost(graphs[i], 1, 12);
		result.searchBoostDurationMatrix += graphs[i]->printTime(1, 12);
		result.boostAllDurationMatrix += graphs[i]->calcBothTime(12);


		graphs[i]->freeAll();

	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());;
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.createBoostDurationMatrixAdj = result.createBoostDurationMatrixAdj / static_cast<double>(graphs.size());
	result.searchBoostDurationAdjList = result.searchBoostDurationAdjList / static_cast<double>(graphs.size());
	result.searchBoostDurationMatrix = result.searchBoostDurationMatrix / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDurationAdjList = result.boostAllDurationAdjList / static_cast<double>(graphs.size());
	result.boostAllDurationMatrix = result.boostAllDurationMatrix / static_cast<double>(graphs.size());
	return result;
}
Duration johnsonExperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.createBoostDurationMatrixAdj = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDurationAdjList = 0.0;
	result.searchBoostDurationMatrix = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDurationAdjList = 0.0;
	result.boostAllDurationMatrix = 0.0;
	using namespace std::chrono;
	high_resolution_clock::time_point begin;
	duration<double> timeSpan;
	for (unsigned int i = 0; i < graphs.size(); i++)
	{

		graphs[i]->freeAll();
		begin = high_resolution_clock::now();
		graphs[i]->standardGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createStandardDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 13, timeSpan.count());
		JohnsonNormal(graphs[i], 1, 13);

		result.searchStadndardDuration += graphs[i]->printTime(1, 13);
		graphs[i]->calcBothTime(13);
		result.standardAllDuration += graphs[i]->printTime(2, 13);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 14, timeSpan.count());
		JohnsonBoost(graphs[i], 1, 14);
		result.searchBoostDurationAdjList += graphs[i]->printTime(1, 14);
		result.boostAllDurationAdjList += graphs[i]->calcBothTime(14);

		
		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedMatrixSimpleGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDurationMatrixAdj += timeSpan.count();
		graphs[i]->setExpTime(0, 15, timeSpan.count());
		JohnsonBoostAdjMatrix(graphs[i], 1, 15);
		
		result.searchBoostDurationMatrix += graphs[i]->printTime(1, 15);
		result.boostAllDurationMatrix += graphs[i]->calcBothTime(15);
		graphs[i]->freeAll();
		
	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());;
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.createBoostDurationMatrixAdj = result.createBoostDurationMatrixAdj / static_cast<double>(graphs.size());
	result.searchBoostDurationAdjList = result.searchBoostDurationAdjList / static_cast<double>(graphs.size());
	result.searchBoostDurationMatrix = result.searchBoostDurationMatrix / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDurationAdjList = result.boostAllDurationAdjList / static_cast<double>(graphs.size());
	result.boostAllDurationMatrix = result.boostAllDurationMatrix / static_cast<double>(graphs.size());
	return result;
}
