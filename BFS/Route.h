#pragma once

#include <iostream>

class Route
{
private:
	std::string fFrom;
	std::string fTo;
	int fDistance;
	size_t fDisplacement;

public:
	Route(std::string aFrom, std::string aTo, int aDistance, size_t aDisplacement);

	std::string getFrom() const;
	std::string getTo() const;
	int getDistance() const;
	size_t getDisplacement() const;

	friend std::ostream& operator<<(std::ostream& aOStream, const Route& aRoute);
};
