#pragma once

#include "Route.h"
#include <list>

#define MAX_ROUTES 100

class Map
{
private:
	Route* fRoutes[MAX_ROUTES + 1];
	size_t fNumberOfRoutes;

public:
	Map();

	size_t getNumberOfRoutes() const;

	void readRoutes(std::istream& aIStream);

	bool checkCityExists(char* cityName) const;
	bool checkBaseExists(char* aCityName) const;
	bool checkDestinationExists(char* aCityName) const;

	std::string* fetchTraversableRoutes(std::string aCityFrom) const;
};
