
#include "DataExp.h"
#include <chrono>
#include "DFSnormal.h"
#include "DFSboost.h"
#include "BFSnormal.h"
#include "BFSboost.h"
#include "FloydWarshallNormal.h"
#include "FloydWarshallBoost.h"
#include "DijkstraNormal.h"
#include "DijkstraBoost.h"
#include "BellmanFordNormal.h"
#include "BellmanFordBoost.h"
#include "JohnsonBoost.h"
#include "JohnsonNormal.h"
Duration DFSexperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration=0.0;
	result.createBoostDuration=0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDuration=0.0;
	result.standardAllDuration=0.0;
	result.boostAllDuration=0.0;
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
		result.searchBoostDuration += graphs[i]->printTime(1, 1);
		result.boostAllDuration += graphs[i]->calcBothTime(1);


	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());
	result.createStandardDuration=result.createStandardDuration / static_cast<double>(graphs.size());
	result.searchBoostDuration = result.searchBoostDuration / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDuration = result.boostAllDuration / static_cast<double>(graphs.size());
	return result;
}
//
Duration BFSexperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDuration = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDuration = 0.0;
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
		result.searchBoostDuration += graphs[i]->printTime(1, 3);
		result.boostAllDuration += graphs[i]->calcBothTime(3);


	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.searchBoostDuration = result.searchBoostDuration / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDuration = result.boostAllDuration / static_cast<double>(graphs.size());
	return result;
}


Duration floydWarshallExperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDuration = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDuration = 0.0;
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
		result.searchBoostDuration += graphs[i]->printTime(1, 5);
		result.boostAllDuration += graphs[i]->calcBothTime(5);
		graphs[i]->freeAll();

	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());;
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.searchBoostDuration = result.searchBoostDuration / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDuration = result.boostAllDuration / static_cast<double>(graphs.size());
	return result;
}
//
Duration dijkstraExperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDuration = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDuration = 0.0;
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
		graphs[i]->setExpTime(0, 6, timeSpan.count());
		dijkstraStandart(graphs[i], 1, 6);

		result.searchStadndardDuration += graphs[i]->printTime(1, 6);
		graphs[i]->calcBothTime(6);
		result.standardAllDuration += graphs[i]->printTime(2, 6);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 7, timeSpan.count());
		dijkstraBoost(graphs[i], 1, 7);
		result.searchBoostDuration += graphs[i]->printTime(1, 7);
		result.boostAllDuration += graphs[i]->calcBothTime(7);
		graphs[i]->freeAll();

	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());;
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.searchBoostDuration = result.searchBoostDuration / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDuration = result.boostAllDuration / static_cast<double>(graphs.size());
	return result;
}
Duration bellmanFordExperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDuration = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDuration = 0.0;
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
		graphs[i]->setExpTime(0, 8, timeSpan.count());
		BellmanFordNormal(graphs[i], 1, 8);

		result.searchStadndardDuration += graphs[i]->printTime(1, 8);
		graphs[i]->calcBothTime(8);
		result.standardAllDuration += graphs[i]->printTime(2, 8);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 9, timeSpan.count());
		BellmanFordBoost(graphs[i], 1, 9);
		result.searchBoostDuration += graphs[i]->printTime(1, 9);
		result.boostAllDuration += graphs[i]->calcBothTime(9);
		graphs[i]->freeAll();

	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());;
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.searchBoostDuration = result.searchBoostDuration / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDuration = result.boostAllDuration / static_cast<double>(graphs.size());
	return result;
}
Duration johnsonExperiment(GraphVector graphs)
{
	Duration result;
	result.createStandardDuration = 0.0;
	result.createBoostDuration = 0.0;
	result.searchStadndardDuration = 0;
	std::cout << "[]";
	result.searchBoostDuration = 0.0;
	result.standardAllDuration = 0.0;
	result.boostAllDuration = 0.0;
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
		JohnsonNormal(graphs[i], 1, 10);

		result.searchStadndardDuration += graphs[i]->printTime(1, 10);
		graphs[i]->calcBothTime(10);
		result.standardAllDuration += graphs[i]->printTime(2, 10);


		begin = high_resolution_clock::now();
		graphs[i]->boostWeightedGraph();
		timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - begin);
		result.createBoostDuration += timeSpan.count();
		graphs[i]->setExpTime(0, 11, timeSpan.count());
		JohnsonBoost(graphs[i], 1, 11);
		result.searchBoostDuration += graphs[i]->printTime(1, 11);
		result.boostAllDuration += graphs[i]->calcBothTime(11);
		graphs[i]->freeAll();

	}
	result.createBoostDuration = result.createBoostDuration / static_cast<double>(graphs.size());;
	result.createStandardDuration = result.createStandardDuration / static_cast<double>(graphs.size());
	result.searchBoostDuration = result.searchBoostDuration / static_cast<double>(graphs.size());
	result.searchStadndardDuration = result.searchStadndardDuration / static_cast<double>(graphs.size());
	result.standardAllDuration = result.standardAllDuration / static_cast<double>(graphs.size());
	result.boostAllDuration = result.boostAllDuration / static_cast<double>(graphs.size());
	return result;
}
