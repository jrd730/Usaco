/*
ID: jrd7301
PROG: milk
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
struct MM //milk maker
{
	int price;
	int avail; 
};
bool operator < ( MM i1,MM i2 ) { return i1.price < i2.price;}
vector <MM> makers;
int main ()
{
	ifstream in ("milk.in");
	ofstream out ("milk.out");
	int N, M;//gallons milk needed, number milk makers
	in >> N >> M;
	for (int i=0; i < M; i++){
		MM mm;
		in >> mm.price >> mm.avail;
		makers.push_back(mm);
	}
	sort(makers.begin(), makers.end());//sort makers by unit price
	int paid=0;
	int i=0;
	while (N){//buy from cheapest source
		if (makers[i].avail < N) {
			paid += makers[i].price * makers[i].avail;
			N -= makers[i].avail;
		}
		else{
			paid += makers[i].price * N;
			N = 0;
		}
		i++;
	}
	
	out << paid << endl;
	
	
	return 0;
}
