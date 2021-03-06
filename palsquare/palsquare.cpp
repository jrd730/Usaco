/*
ID: jrd7301
PROG: palsquare
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
	ifstream in ("palsquare.in");
	ofstream out ("palsquare.out");
	
	int N;
	in >> N;
	
	for (int i=1; i <= 300; i++){
		string s1 = nToBase(i, N);
		string s2 = nToBase(i*i, N);
		
		//cout << s1 << " " << s2 << endl;
		
		if (palindrome(s2)){
			out << s1 << " " << s2 << endl;
		}
	}
	
	return 0;
}
