#ifndef  __MANAGETRIPS_H
#define __MANAGETRIPS_H
#include "Trip.h"
class ManagementTrips
{
private:
	Trip** arrTrips;
	int idx;
public:
	//check how to do constructor
	ManagementTrips();
	ManagementTrips(const ManagementTrips& m);
	const ManagementTrips& operator=(const ManagementTrips& m);

};

#endif // !__MANAGETRIPS_H
