#include "Map.h"
#include "BFS.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cerr << "Arguments missing." << endl << "Usage: BFS <filename> <base> <destination>" << endl;
		return 1; // Error: CLI Argument Error
	}

	// Open Data File In Read Mode
	ifstream lInput(argv[1]);

	if (!lInput.good())
	{
		cerr << "Cannot open input file: " << argv[1] << endl;
		return 2; // Error: Could Not Open Data File
	}

	// Load Routes Onto Map
	Map lMap;
	lMap.readRoutes(lInput);

	if (!lMap.checkCityExists(argv[2]))
	{
		cerr << "City '" << argv[2] << "' not found.";
		return 3; // Error: Could Not Find Base City
	}
	if (!lMap.checkCityExists(argv[3]))
	{
		cerr << "City '" << argv[3] << "' not found.";
		return 4; // Error: Could Not Find Destination City
	}
	
	// Find Route Using Bread-First Search
	BFS(lMap, argv[2], argv[3])();

	lInput.close();

	return 0; // Success
}
