/*
ID: jrd7301
PROG: calfflac
LANG: C++
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool ignore (char c)
{
  string ignored ("\n\t ,.-_`'+=;:\"?!<>\\/[]{}()|~&*^%#@0123456789");
  for (int i=0; i < ignored.length(); i++) {
    if (c==ignored[i]) return true;
  }
  return false;
}

int main ()
{
	ifstream in ("calfflac.in");
	ofstream out ("calfflac.out");
	
	string original("");
	string text("");
	vector <int> tmap;
	tmap.resize(20001);
	int index = 0;
	
	int pos = 0;
	while (in.good())
	{
	  char c = in.get();
	  if (!in.eof());
	  {
	    original += c;
	    
	    if (!ignore (c)){
	      text += tolower(c);
	      tmap[index] = pos;
	      index++;
	    }
	    pos++;
	  }
	}
	text.erase (text.length()-1);
	//text.erase (text.length()-1);
	
	int longestPalindrome = 1;
	int tstart = 0, tend = 0; 
	int ostart = 0, oend = 0;
	int mstart = 0, mend = original.length()-1;   
	//try to make a palindrome centered at every letter
	for (int i=0; i<text.length(); i++)
	{
  	//try odd length palindrome
	  int pstart = i-1, pend = i+1;
	  while (pstart >= 0 && pend < text.length() && text[pstart] == text[pend]){
	    pstart--; pend++;
	  }
	  pstart++; pend--;
	  int psize = pend - pstart + 1;
	  if (psize > longestPalindrome){
	     longestPalindrome = psize;
	     tstart = pstart;
	     tend = pend;  
	  }
	  
	  //try even length palindrome
	  pstart = i, pend = i+1;
	  while (pstart >= 0 && pend < text.length() && text[pstart] == text[pend]){
	    pstart--; pend++;
	  }
	  pstart++; pend--;
	  psize = pend - pstart + 1;
	  if (psize > longestPalindrome){
	     longestPalindrome = psize;
	     tstart = pstart;
	     tend = pend;
	  } 
	}
	
	//cout << text << endl;
	//cout << text.size() << endl;
	out << longestPalindrome << endl;
	//out << text.substr(tstart, longestPalindrome) << endl;
	out << original.substr(tmap[tstart], tmap[tend]-tmap[tstart]+1) << endl;
//	cout << original.substr(ostart, oend-ostart) << endl;
	
	return 0;
}
