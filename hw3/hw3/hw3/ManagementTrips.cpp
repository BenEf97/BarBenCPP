#include "ManagementTrips.h"

//Empty constructor
ManagementTrips::ManagementTrips()
{
	arrTrips = new Trip*[0];
	idx = 0;
}

//copy constructor for ManagmentTrips
ManagementTrips::ManagementTrips(const ManagementTrips & m)
{
	idx = m.idx;
	*arrTrips = new Trip[m.idx];
	for (int i=0;i<idx;i++)
	{

		arrTrips[i] = new Trip[sizeof(m.arrTrips[i])];

		//= operator for trip
		arrTrips[i] = m.arrTrips[i];
	}
}

// '=' operator
const ManagementTrips & ManagementTrips::operator=(const ManagementTrips & m)
{
	//allocating memory for double array
	*arrTrips = new Trip[m.idx];

		for (int i = 0; i < m.idx; i++) {
			//allocating new memory
			arrTrips[i] = new Trip[sizeof(m.arrTrips[i])];

			//= operator for trip
			arrTrips[i] = m.arrTrips[i];
		}
		idx = m.idx;
	
	return *this;
}

// '+=' operator
const ManagementTrips & ManagementTrips::operator+=(const Trip & t)
{
	arrTrips[idx] = new Trip[1];
	*arrTrips[idx] = t;
	idx++;
	return *this;
}

// '-=' operator
const ManagementTrips & ManagementTrips::operator-=(const Trip & t)
{
	
	//searching for the date
	for(int i=0;i<idx;i++)
	{
		//matching date found
		if (arrTrips[i]->getDate()==t.getDate())
		{
			//remove the trip
			delete []arrTrips[i];
			int j;
			for (j = i; j < idx-1; j++)
			{
				arrTrips[j] = arrTrips[j + 1];

			}
			arrTrips[j] = NULL;
			//delete last
			idx--;
			i--;
		}
	}
	return *this;
}


// '<<' operator
ostream & operator<<(ostream & os, const ManagementTrips& m)
{
	//checking if the array is empty
	if (m.idx == 0)
		os << "The array is empty";
	else
	for (int i=0;i<m.idx;i++)
	{
		os << *m.arrTrips[i];
	}
	return os;
}
