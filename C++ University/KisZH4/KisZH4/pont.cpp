#include "pont.h"

#include <cmath>
using namespace std;

Pont::Pont():
	esz(0),
	kh(0)
{
}

Pont::Pont(double esz, double kh):
	esz(esz),
	kh(kh)
{
}

double Pont::lat() const
{
	return esz;
}

double Pont::lon() const
{
    return kh;
}

double Pont::tavolsag(const Pont &masik) const
{
    // https://en.wikipedia.org/wiki/Haversine_formula
    auto toRad = [](double fok){
        return fok*3.14159265358979323846/180;
    };
    double lat1=toRad(esz), lat2=toRad(masik.esz);
    double lon1=toRad(kh), lon2=toRad(masik.kh);
    double temp1 = sin((lat2-lat1)/2);
    double temp2 = sin((lon1-lon2)/2);
    double temp3 = temp1*temp1+cos(lat1)*cos(lat2)*temp2*temp2;
    double earthRadius = 6371;
    return 2*earthRadius*asin(sqrt(temp3));
}
