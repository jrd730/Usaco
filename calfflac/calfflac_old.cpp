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
  string ignored ("\n\t ,.-_`'+=;:\"?!<>\\/[]{}()|~&*^%#@");
  for (int i=0; i < ignored.length(); i++) {
    if (c==ignored[i]) return true;
  }
  return false;
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
	ifstream in ("calfflac.in");
	ofstream out ("calfflac.out");
	
	string original("");
	string text("");
	
	while (in.good())
	{
	  char c = in.get();
	  if (!in.eof());
	  {
	    original += c;
	    if (!ignore(c))
	      text += tolower(c);
	  }
	}
	text.erase (text.length()-1);
	//text.erase (text.length()-1);
	
	int pstart = 0, pend = 0, longestPalindrome = 2;
	int ostart = 0, oend = 0;
	int mstart = 0, mend = original.length()-1; 
	
	for (int i=0; i<text.length(); i++)
	{
	  //while (tolower(original[mstart]) != text[i]){mstart++;}
	  
	   for (int j=text.length(); j > i; j--)
	   {
	      //while (tolower(original[mend]) != text[j]){mend--;}
	      
	      int length = j-i;
	      cout << text.substr(i, length) << endl;
	      //cout << original.substr(mstart, mend-mstart) << endl;
	      if (palindrome(text.substr(i, length))){
	     
	        if (length > longestPalindrome){
	          longestPalindrome = length;
	          pstart = i;
	          pend = j;
	          ostart = mstart;
	          oend = mend;
	         }
	      }
	   }
	}
	
	cout << text << endl;
	
	cout << longestPalindrome << endl;
	cout << text.substr(pstart, longestPalindrome) << endl;
//	cout << original.substr(ostart, oend-ostart) << endl;
	
	return 0;
}
