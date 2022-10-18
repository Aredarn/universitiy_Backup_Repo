#include "distances.h"
#include <iostream>
#include <algorithm>
#include <numeric>

Distances::Distances(const string &_currentCity):
	currentCity(_currentCity)
{
}

string Distances::getCurrentCity() const
{
	return currentCity;
}
