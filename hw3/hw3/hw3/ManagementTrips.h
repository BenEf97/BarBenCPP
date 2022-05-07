#ifndef  __MANAGETRIPS_H
#define __MANAGETRIPS_H
#include "Trip.h"
class ManagementTrips
{
private:
	Trip** arrTrips;
	int idx;
public:
	ManagementTrips();
	ManagementTrips(const ManagementTrips& m);
	const ManagementTrips& operator=(const ManagementTrips& m);
	const ManagementTrips& operator+=(const Trip& t);
	const ManagementTrips& operator-=(const Trip& t);
	friend ostream& operator<<(ostream& os, const ManagementTrips& m);
};

#endif // !__MANAGETRIPS_H
