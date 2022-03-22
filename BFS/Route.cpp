#include "Route.h"

// Initialize Fields
Route::Route(std::string aFrom, std::string aTo, int aDistance, size_t aDisplacement) :
	fFrom(aFrom), fTo(aTo), fDistance(aDistance), fDisplacement(aDisplacement)
{}

// Return Base City
std::string Route::getFrom() const
{
	return fFrom;
}

// Return Destination City
std::string Route::getTo() const
{
	return fTo;
}

// Return Actual Distance of Route
int Route::getDistance() const
{
	return fDistance;
}

// Return Route Displacement
size_t Route::getDisplacement() const
{
	return fDisplacement;
}

// Return Output Stream Containing Route Information
std::ostream& operator<<(std::ostream& aOStream, const Route& aRoute)
{
	if (aRoute.fDistance < 0)
	{
		return aOStream << "Cannot drive from " << aRoute.fFrom << " to " << aRoute.fTo
			<< ", however, there is a straight line distance of " << aRoute.fDisplacement << ".";
	}
	return aOStream << "Travel from " << aRoute.fFrom << " to " << aRoute.fTo
		<< " with a straight line distance of " << aRoute.fDisplacement
		<< " and an actual distance of " << aRoute.fDistance << ".";
}
