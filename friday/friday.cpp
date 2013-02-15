/*
ID: jrd7301
PROG: friday
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool isLeapYear (int year) {return ((year % 4 == 0) && ( (year % 100 != 0) || (year % 400 == 0)));}

const int days_in_month [] 			= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int leap_days_in_month [] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int startYear = 1900;
int weekDay = 2; // Monday;
int dayIs13th [] = {0, 0, 0, 0, 0, 0, 0}; // Sat - Sun

int main ()
{
	ifstream in ("friday.in");
	ofstream out ("friday.out");

	int N;
	in >> N;
	int endYear = startYear + N;
	
	for (int i = startYear; i < endYear; i++)
	{
		bool leapYear = isLeapYear (i);
		
		for (int j = 0; j < 12; j++)
		{
			int daysOfMonth;
		
			if (leapYear) daysOfMonth = leap_days_in_month [j];
			else daysOfMonth = days_in_month [j];
		
			for (int k = 0; k < daysOfMonth; k++)
			{
				if (k == 12) dayIs13th[weekDay]++;
				
				weekDay++;
				if (weekDay == 7) weekDay = 0;
			}
		}
	}
	
	for (int i=0; i<7; i++)
	{
		out << dayIs13th[i];
		if (i < 6) out << " ";
	}
	out << endl;
	
	return 0;
}
