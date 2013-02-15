/*
ID: jrd7301
PROG: namenum
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

int hashToPad (int num) {return num-2;}

const int padMap [8][3] = {
													{'A', 'B', 'C'}, //2
													{'D', 'E', 'F'}, //3 
													{'G', 'H', 'I'}, //4
													{'J', 'K', 'L'}, //5
													{'M', 'N', 'O'}, //6
													{'P', 'R', 'S'}, //7
													{'T', 'U', 'V'}, //8
													{'W', 'X', 'Y'}  //9
												};


int main ()
{
	ifstream in ("dict.txt");
	ofstream out ("namenum.out");
	
	// map to contain all valid names
	map <string, int> names;
	
	//read in name file
	while (in.good())
	{
		string temp("");
		in >> temp;
		names[temp] = 1;
	}
	
	in.close ();
	in.open ("namenum.in");
	
	string cowCode(""); // cow code as a string
	in >> cowCode;
	
	int codeLength = cowCode.length();
	int code[codeLength]; // array of one digit numbers (2 - 9) that represent the cow code
	
	for (int i=0; i<codeLength; i++){
		code[i] = cowCode[i] - 48; // 2 has ascii value 50
	}
	
	int	c [codeLength]; // array of counters
	fill(c, c+codeLength, 0);
	
	bool nameFound = false;
	
	//iterate through every possible combination of letters 
	//that can be made with the cow's code sequence
	while (c[0] < 3)
	{
		string combo("");
		
		for (int i = 0; i < codeLength; i++)
		{
			combo += padMap [ hashToPad( code[i] )] [c[i]];
		}
		
		map <string, int> :: iterator it;
		it = names.find(combo); //check if letter combo is a valid name
		
		if (it != names.end()){
		 out << combo << endl;
		 nameFound = true;
		}
		
		c[codeLength-1]++;
		
		for (int i = codeLength - 1; i > 0; i--)
		{
			if (c[i] == 3){
			 	c[i - 1]++;
				c[i] = 0;
			}
		}
	}
	
	if (!nameFound) out << "NONE" << endl;
	
	return 0;
}
