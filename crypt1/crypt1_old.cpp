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

int main ()
{
	ifstream in ("crypt1.in");
	ofstream out ("crypt1.out");
	
	int N;
	in >> N;
	
	int d[N];
	for (int i=0; i<N; i++){
	  in >> d[i];
	}
	
	int c[5];
	fill(c, c+5, 0);
	
	int num1   [3];
	int num2   [2];
	int part1  [3];
	int part2  [3];
	int sum    [4];
	
	int solutions = 0;
	int tries = 0;
	while (c[0] < N)
	{
	  bool found[10];
    fill (found, found + 10, false);
	
    num1[0] = d[c[0]];
    num1[1] = d[c[1]];
    num1[2] = d[c[2]];
    
    num2[0] = d[c[3]];
    num2[1] = d[c[4]];
   
    found[num1[0]] = true;
    found[num1[1]] = true;
    found[num1[2]] = true;
   
    found[num2[0]] = true;
    found[num1[1]] = true;
   
    part1[2] = num1[2] * num2[1];
    int carry = part1[2]/10;
    part1[2] %= 10;
    found[part1[2]] = true;
    
    
    part1[1] = num1[1] * num2[1] + carry;
     carry = part1[1]/10;
    part1[1] %= 10;
    found[part1[1]] = true;
    
    
    part1[0] = num1[0] * num2[1] + carry;
     carry = part1[0]/10;
    part1[0] %= 10;
    found[part1[0]] = true;
    
    part2[2] = num1[2] * num2[0];
     carry = part2[2]/10;
    part2[2] %= 10;
    found[part2[2]] = true;
    
    part2[1] = num1[1] * num2[0] + carry;
     carry = part2[1]/10;
    part2[1] %= 10;
    found[part1[1]] = true;
    
    part2[0] = num1[0] * num2[0] + carry;
     carry = part2[0]/10;
    part2[0] %= 10;
    found[part1[0]] = true;
    
    sum[3] = part1[2];
    
    sum[2] = part1[1] + part2[2];
     carry = sum[2]/10;
    sum[2] %= 10;
    found[sum[2]] = true;
    
    sum[1] = part1[0] + part2[1] + carry;
     carry = sum[1]/10;
    sum[1] %= 10;
    found[sum[1]] = true;
    
    sum[0] = part2[0] + carry;
     carry = sum[0]/10;
    sum[0] %= 10;
    found[sum[0]] = true;
   
   bool allFound = true;
   for (int i=0; i<N; i++){
    if (!found[d[i]]) allFound = false;
   }
   
   if (allFound) {
      solutions++;
      
      cout << "   " << num1[0] << num1[1] << num1[2] << endl
           << "  X " << num2[0] << num2[1] << endl
           << "--------" << endl
           << "  " << part1[0] << part1[1] << part1[2] << endl
           << " " << part2[0] << part2[1] << part2[2] << endl
           << "--------" << endl 
           << sum[0] << sum[1] << sum[2] << sum[3] << endl << endl;
      
   }
   
   c[4]++;
   for (int i=4; i>0; i--)
   {
      if (c[i] >= N){
        c[i-1]++;
        c[i] = 0;
      }
   }
   tries++;
	}
	
	
	for (int i=0; i<N; i++){
	 cout << d[i] << " ";
	}
	cout << endl;
	cout << solutions << endl << tries << endl;
	return 0;
}
