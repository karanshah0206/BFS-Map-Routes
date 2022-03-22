#include "Map.h"

// Initialize Fields
Map::Map()
{
	fNumberOfRoutes = 0;
	for (int i = 0; i < MAX_ROUTES; i++) fRoutes[i] = {};
}

// Return All Routes On Map (Including Untraversable Ones)
size_t Map::getNumberOfRoutes() const
{
	return fNumberOfRoutes;
}

// Load Routes Onto fRoutes From An Input Stream.
void Map::readRoutes(std::istream& aIStream)
{
	while (!aIStream.eof())
	{
		char lRouteDetails[4][200];

		for (int i = 0; i < 4; i++)
		{
			// When i = 3, default new line (\n) delimiter
			if (i != 3)
				aIStream.getline(lRouteDetails[i], 50, ' ');
			else
				aIStream.getline(lRouteDetails[i], 50);
		}

		fNumberOfRoutes++;
		fRoutes[fNumberOfRoutes - 1] = new Route(lRouteDetails[0], lRouteDetails[1], atoi(lRouteDetails[2]), atoi(lRouteDetails[3]));
	}
}

// Check If City Exists On The Map
bool Map::checkCityExists(char* aCityName) const
{
	if (checkBaseExists(aCityName) || checkDestinationExists(aCityName))
		return true;
	return false;
}

// Check If Any Routes Start From Specified City
bool Map::checkBaseExists(char* aCityName) const
{
	for (size_t i = 0; i < fNumberOfRoutes; i++)
		if (fRoutes[i]->getFrom() == aCityName)
			return true;
	return false;
}

// Check If Any Routes Lead From Specified City
bool Map::checkDestinationExists(char* aCityName) const
{
	for (size_t i = 0; i < fNumberOfRoutes; i++)
		if (fRoutes[i]->getTo() == aCityName)
			return true;
	return false;
}

// Return Array Of City Names With Direct Route To Specified City
std::string* Map::fetchTraversableRoutes(std::string aCityFrom) const
{
	std::string* lRoutes = new std::string[MAX_ROUTES];
	int lRoutesSize = 0;

	for (int i = 0; i < fNumberOfRoutes; i++)
	{
		// Do Not Consider Untraversable Routes
		if (fRoutes[i]->getFrom() == aCityFrom && fRoutes[i]->getDistance() >= 0)
		{
			lRoutes[lRoutesSize] = fRoutes[i]->getTo();
			lRoutesSize++;
		}
	}

	return lRoutes;
}
