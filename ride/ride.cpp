/*
ID: jrd7301
PROG: ride
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main ()
{
	ifstream in ("ride.in");
	ofstream out ("ride.out");
	
	string g_name ("");
	string c_name ("");
	
	int g_val = 1;
	int c_val = 1;
	
	in >> g_name >> c_name;

	for (int i=0; i < g_name.length(); i++)
	{
		g_val *= g_name[i] - 64;
	}

	for (int i=0; i < c_name.length(); i++)
	{
		c_val *= c_name[i] - 64;
	}
	
	if (g_val % 47 == c_val % 47)
		out << "GO";
	else
		out << "STAY";
	
	out << endl;
	return 0;
}
