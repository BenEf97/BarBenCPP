#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "MousseCake.h"
#include "BirthdayCake.h"
#include <iostream>

using namespace std;

void main()
{
	try
	{
		Date d1(18, 8);
		Date d2(d1);
		Date d3(26, 8, 2021);

		Cake cake1(d1, 24, 9.5, 258.9, 1, true);
		cout << cake1;// OR cake1.show()
		cout << endl;

		MousseCake mc1(d3, 18, 9.5, 190, 2, true, "white chocolate");
		cout << mc1;// OR mc1.show()
		cout << endl;

		MousseCake* mc2 = new MousseCake(d2, 20, 8, 200, 1, false, "kinder bueno");
		cout << *mc2; // OR mc2->show()
		cout << endl;

		MousseCake mc3(*mc2);
		cout << "(mc3==*mc2): " << (mc3 == *mc2 ? "true\n" : "false\n");
		cout << endl;

		BirthdayCake bc1(d1, 24, 9.5, 289.9, 2, true, "mazal tov");
		cout << bc1; // OR bc1.show()
		cout << endl;

		BirthdayCake bc2(d2, 22, 9, 270, 1, true, "sweet 30");
		bc2 = bc1;
		cout << bc2;// OR bc2.show()
		cout << endl;

		cake1 += 40;
		cout << cake1;// OR cake1.show()
		cout << endl;

		bc2 += 50;
		cout << bc2;// OR bc2.show()
		cout << endl;
		delete mc2;
		system("pause");
	}
	catch (char* excaption)
	{
		cout << excaption;
	}
}