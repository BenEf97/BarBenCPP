#include "ManagementTrips.h"

ManagementTrips::ManagementTrips()
{
	arrTrips = NULL;
	*arrTrips = new Trip[0];
	idx = 0;
}

const ManagementTrips & ManagementTrips::operator=(const ManagementTrips & m)
{
	//allocating memory for double array
	arrTrips = NULL;
	*arrTrips = new Trip[m.idx];
		//= operator for trip
		for (int i = 0; i < m.idx; i++) {
			//allocating new memory
			arrTrips[i] = NULL;
			arrTrips[i] = new Trip[sizeof(m.arrTrips[i])];
			arrTrips[i] = m.arrTrips[i];
		}
		idx = m.idx;
	
	return *this;
}

//Copy constructor and '=' operator (later)



