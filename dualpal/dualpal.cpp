/*
ID: jrd7301
PROG: dualpal
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

const char c [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
									 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K'};

string nToBase (int n, int base)
{
	string s("");
	int pos = 1;
	while ( pos*base < n ){
	  pos *= base;
	}
	while (pos){
		s += c[n/pos];
		n %= pos;
		pos /= base;
	}
	return s;
}

bool palindrome (string s)
{
	for (int i=0; i<s.length()/2; i++){
		if( s[i] != s[ s.length()-i-1 ] ) 
			return false;
	}
	return true;
} 

int main ()
{
	ifstream in ("dualpal.in");
	ofstream out ("dualpal.out");
	
	int N, S, n(0);
	in >> N >> S;

	for (int s = S+1; s < 100000; s++)
	{
		int found = 0;
		string str("");
		for (int i=2; i <= 10; i++)
		{
			str = nToBase(s, i);
			if ( palindrome (str) ){
				if (found >= 2) break;
				found++;
			}
		}
		if (found >= 2){
			out << s << endl;
			n++;
			if (n >= N) break;
		}
	}
	
	return 0;
}
