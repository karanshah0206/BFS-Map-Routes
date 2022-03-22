#pragma once

#include "Map.h"

class BFS
{
private:
	Map fMap;
	std::string fCurrentState;
	std::string fGoalState;
	std::string fFrontier[MAX_ROUTES + 1];
	size_t fParentsRecord[MAX_ROUTES + 1];
	size_t fFrontierSize;
public:
	BFS(Map aMap, std::string aCurrentState, std::string aGoalState);

	bool isOnFrontier(std::string aCityName) const;

	void printRoute(size_t aNodeIndex) const;
	void operator()();
};
