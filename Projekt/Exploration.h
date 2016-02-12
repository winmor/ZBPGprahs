
#include "DataExp.h"

typedef std::map<unsigned int, GraphVector> probeCount;

void exploration();

probeCount createGraphs(size_t sizes[], size_t length, size_t numberProbesl, unsigned short fill);
