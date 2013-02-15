/*
ID: jrd7301
PROG: gift1
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
	ifstream in ("gift1.in");
	ofstream out ("gift1.out");
	
	int giverCount = 0;
	in >> giverCount;
	
	vector <string> name;
	map <string, int> account;
	
	for (int i = 0; i < giverCount; i++)
	{
		string tempName ("");
		in >> tempName;
		
		name.push_back(tempName);
		account[tempName] = 0;
	} 
	
	for (int i = 0; i < giverCount; i++)
	{
		string giver("");
		in >> giver;
		
		int budget;
		in >> budget;
		account[giver] -= budget;
		
		int splitWays;
		in >> splitWays;
		
		if (splitWays != 0)
		{
			int alotment = budget / splitWays;
			account[giver] += budget % splitWays;
		
			for (int j=0; j < splitWays; j++)
			{
				string receiver("");
				in >> receiver;
			
				account[receiver] += alotment;
				
				//cout << giver << " has given " << alotment << " to " << receiver << endl;
			}
			
			//cout << giver << " has a remaining balance of " << account[giver] << endl;
			
		}
	}
	
	for (int i=0; i<giverCount; i++)
	{
		out << name[i] << " " << account [name[i]] << endl;
		//cout << name[i] << " " << account [name[i]] << endl;
	}
	
	//cout << endl;
	
	return 0;
}
