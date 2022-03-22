#include "BFS.h"

using namespace std;

// Initialize Fields
BFS::BFS(Map aMap, string aCurrentState, string aGoalState) :
	fMap(aMap), fCurrentState(aCurrentState), fGoalState(aGoalState)
{
	fFrontier[0] = fCurrentState;
	fParentsRecord[0] = 0;
	fFrontierSize = 1;
}

// Check If Node Exists On The Frontier
bool BFS::isOnFrontier(string aCityName) const
{
	for (int i = 0; i < fFrontierSize; i++)
		if (fFrontier[i] == aCityName && aCityName != fCurrentState)
			return true;
	return false;
}

// Recursively Print Path From Base Node To Node At Specified Index
void BFS::printRoute(size_t aNodeIndex) const
{
	if (aNodeIndex != fParentsRecord[aNodeIndex])
	{
		printRoute(fParentsRecord[aNodeIndex]);
		cout << " -> ";
	}

	cout << fFrontier[aNodeIndex];
}

// Commence BFS
void BFS::operator()()
{
	cout << endl << "#################################################" << endl
		<< "Breadth-First Search Commenced ("
		<< fCurrentState << " to " << fGoalState << ")." << endl << endl;

	int lFrontierIndex = 0;
	string lLastState = "";

	do {
		// Current State = First Node On Frontier
		fCurrentState = fFrontier[lFrontierIndex];

		// Check If Current State Is Goal State
		if (fCurrentState == fGoalState)
		{
			cout << "Goal State Reached." << endl << "Path: ";
			printRoute(lFrontierIndex);
			cout << endl;
			break;
		}

		// Check No Path Found
		else if (fCurrentState.empty() || lLastState == fCurrentState)
		{
			cout << "No path found." << endl;
			break;
		}

		// Expand Current Node
		else if (!isOnFrontier(fCurrentState))
		{
			// Add Nodes Not On Already In Queue To End Of Frontier (FIFO)
			string* lFetchedRoutes = fMap.fetchTraversableRoutes(fCurrentState);
			if (!lFetchedRoutes[0].empty())
				for (int i = 0; i < MAX_ROUTES; i++)
					if (!lFetchedRoutes[i].empty() && !isOnFrontier(lFetchedRoutes[i]))
					{
						fFrontier[fFrontierSize] = lFetchedRoutes[i];
						fParentsRecord[fFrontierSize] = lFrontierIndex;
						fFrontierSize++;
					}
		}

		// Move To Next Node On Frontier
		lFrontierIndex++;
		lLastState = fCurrentState;
	} while (true);

	// Print All Nodes In Frontier Queue
	cout << endl << "Frontier Snapshot: ";
	for (int i = 0; i < fFrontierSize; i++)
	{
		cout << fFrontier[i];
		if (i == lFrontierIndex) cout << "*";
		cout << " ";
	}
	cout << endl << "Frontier explored up until \"*\"." << endl;

	cout << endl << "Breadth-First Search Ends." << endl
		<< "#################################################" << endl;
}
