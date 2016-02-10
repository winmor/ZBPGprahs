#include "Graph.h"
#ifndef _H__MEMBER_
#define _H__MEMBER_
struct Duration
{
	double createStandardDuration;
	double createBoostDuration;
	double searchStadndardDuration;
	double searchBoostDuration;
	
	double standardAllDuration;
	double boostAllDuration;
};

typedef std::vector<std::shared_ptr<Graph>> GraphVector;

Duration DFSexperiment(GraphVector graphs);
Duration BFSexperiment(GraphVector graphs);
//Duration bellmanExperiment(GraphVector graphs);
//Duration floydWarshalExperiment(GraphVector graphs);
//Duration dijkstraExperiment(GraphVector graphs);
//Duration johnsonExperiment(GraphVector graphs);
#endif