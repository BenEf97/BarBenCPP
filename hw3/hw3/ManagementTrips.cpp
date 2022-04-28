#include "ManagementTrips.h"

ManagementTrips::ManagementTrips()
{
	//arrTrips = NULL;
	*arrTrips = new Trip[0];
	idx = 0;
}

ManagementTrips::ManagementTrips(const ManagementTrips & m)
{
	idx = m.idx;
	//arrTrips = NULL;
	*arrTrips = new Trip[m.idx];
	for (int i=0;i<idx;i++)
	{

		//arrTrips[i] = NULL;
		arrTrips[i] = new Trip[sizeof(m.arrTrips[i])];

		//= operator for trip
		arrTrips[i] = m.arrTrips[i];
	}
}

const ManagementTrips & ManagementTrips::operator=(const ManagementTrips & m)
{
	//allocating memory for double array
	//arrTrips = NULL;
	*arrTrips = new Trip[m.idx];

		for (int i = 0; i < m.idx; i++) {
			//allocating new memory
			//arrTrips[i] = NULL;
			arrTrips[i] = new Trip[sizeof(m.arrTrips[i])];

			//= operator for trip
			arrTrips[i] = m.arrTrips[i];
		}
		idx = m.idx;
	
	return *this;
}

const ManagementTrips & ManagementTrips::operator+=(const Trip & t)
{
	arrTrips[idx] = new Trip[sizeof(t)];
	*arrTrips[idx] = t;
	idx++;
}

const ManagementTrips & ManagementTrips::operator-=(const Trip & t)
{
	//searching for the date
	for(int i=0;i<idx;i++)
	{
		//matching date found
		if (arrTrips[i]->getDate==t.getDate)
		{
			arrTrips[i]->~Trip;
			int j;
			for (j = i; j < idx-1; j++)
			{
				arrTrips[j] = arrTrips[j + 1];

			}
			arrTrips[j] = NULL;
			//delete last
			idx--;
		}
	}
}



ostream & operator<<(ostream & os, const ManagementTrips& m)
{
	//checking if the array is empty
	if (m.idx == 0)
		os << "The array is empty";
	else
	for (int i=0;i<m.idx;i++)
	{
		os <<"Trip number: "<<i<<":\n"<< m.arrTrips[i];
	}
	return os;
}
