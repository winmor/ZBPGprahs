
#include "DataExp.h"
#include <chrono>
#include "DFSnormal.h"
#include "DFSboost.h"
#include "BFSnormal.h"
#include "BFSboost.h"
//
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
	result.createBoostDuration = result.createBoostDuration / graphs.size();
	result.createStandardDuration=result.createStandardDuration / graphs.size();
	result.searchBoostDuration = result.searchBoostDuration / graphs.size();
	result.searchStadndardDuration = result.searchStadndardDuration / graphs.size();
	result.standardAllDuration = result.standardAllDuration / graphs.size();
	result.boostAllDuration = result.boostAllDuration / graphs.size();
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
	result.createBoostDuration = result.createBoostDuration / graphs.size();
	result.createStandardDuration = result.createStandardDuration / graphs.size();
	result.searchBoostDuration = result.searchBoostDuration / graphs.size();
	result.searchStadndardDuration = result.searchStadndardDuration / graphs.size();
	result.standardAllDuration = result.standardAllDuration / graphs.size();
	result.boostAllDuration = result.boostAllDuration / graphs.size();
	return result;
}
//
//Duration bellmanExperiment(GraphVector graphs)
//{
//	return Duration();
//}
//
//Duration floydWarshalExperiment(GraphVector graphs)
//{
//	return Duration();
//}
//
//Duration dijkstraExperiment(GraphVector graphs)
//{
//	return Duration();
//}
//
//Duration johnsonExperiment(GraphVector graphs)
//{
//	return Duration();
//}
