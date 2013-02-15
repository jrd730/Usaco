/*
ID: jrd7301
PROG: beads
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

int beadCount;
string beads;

int next (int bead){
	bead++; 
	if (bead >= beads.length()) bead = 0; 
	return bead;}
	
int previous (int bead){
	bead--; 
	if (bead < 0) bead = beads.length() - 1;
	return bead; }

int main ()
{
	ifstream in ("beads.in");
	ofstream out ("beads.out");
	
	in >> beadCount >> beads;
	
	int maxCount = 0;
	
	for (int i = 0; i < beads.length(); i++)
	{
		int iFwd = i, 
					iRev = previous(i);
		
		int countFwd = 0, 
					countRev = 0;
		
		char cFwd = beads[iFwd], 
					cRev = beads[iRev];
		
		bool fwdGo = true, 
					revGo = true;
		
		while (fwdGo && (countFwd + countRev < beads.length()))
		{
				if (beads[iFwd] == 'w')
				{
					countFwd++;
				}
				else if (beads[iFwd] == cFwd || cFwd == 'w')
				{
					countFwd++;
					if (cFwd == 'w') cFwd = beads[iFwd];			
				}
				else fwdGo = false;

				iFwd = next (iFwd);
		}
		
		while (revGo && (countFwd + countRev < beads.length()))
		{
				if (beads[iRev] == 'w')
				{
					countRev++;
				}
				else if (beads[iRev] == cRev || cRev == 'w')
				{
					countRev++;
					if (cRev == 'w') cRev = beads[iRev];			
				}
				else revGo = false;
	
				iRev = previous (iRev);
		}
		if (countFwd + countRev > maxCount) maxCount = countFwd + countRev;
	}
	
	out << maxCount << endl;
	
	return 0;
}
