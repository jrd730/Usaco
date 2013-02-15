/*
ID: jrd7301
PROG: transform
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

#define ROTATED_90 1
#define ROTATED_180 2
#define ROTATED_270 3
#define REFLECTED 4
#define COMBINATION 5
#define NO_CHANGE 6
#define INVALID 7

char** transform (char** c, int N)
{
	char** t;
	t = new char* [N];
	for (int i=0; i < N; ++i){
		t[i] = new char [N];
	}

	for (int i=0; i < N; ++i){
		for (int j=0; j < N; ++j){
			
			int y = -i + N/2;
			if (N%2 == 0 && i >= N/2) y--;
			
			int x = j - N/2;
			if (N%2 == 0 && j >= N/2) x++;
			
			int z = y;
			y = -x;
			x = z;
			
			if (N%2 == 0 && y < 0) y++;
			y = -(y - N/2);
			
			if (N%2 == 0 && x > 0) x--;
			x = x + N/2;
			
			t[y][x] = c[i][j];
		}
	}	
	return t;
}

char** mirror (char** c, int N)
{
	char** t;
	t = new char* [N];
	for (int i=0; i < N; ++i){
		t[i] = new char [N];
	}

	for (int i=0; i < N; ++i){
		for (int j=0; j < N; ++j){
					
			int x = j - N/2;
			if (N%2 == 0 && j >= N/2) x++;
			
			x = -x;
			
			if (N%2 == 0 && x >= 0) x--;
			x = x + N/2;
			
			t[i][x] = c[i][j];
		}
	}	
	return t;
}

bool match (char** l, char** r, int N)
{
	for (int i=0; i < N; ++i){
		for (int j=0; j < N; ++j){
			if (l[i][j] != r[i][j]) 
				return false;
		}
	}return true;
}

int main ()
{
	ifstream in ("transform.in");
	ofstream out ("transform.out");
	
	int N;
	in >> N;
	in.get();

	char** c; //original shape
	c = new char* [N];
	for (int i=0; i < N; i++){
		c[i] = new char [N];
		for (int j=0; j < N; j++){
			c[i][j] = in.get();
		}
		in.get();
	}
	
	char** d; //comparison shape
	d = new char* [N];
	for (int i=0; i < N; ++i)	{
		d[i] = new char [N];
		for (int j=0; j < N; ++j){
			d[i][j] = in.get();
		}
		in.get();
	}
	
	bool found = false;
	
	char** t = transform(c, N);
	
	if (match (t, d, N) && !found){
	 out << ROTATED_90 << endl;
	 found = true;
	}
	
	t = transform (t, N);
	
	if (match (t, d, N ) && !found){
		out << ROTATED_180 << endl;
		found = true;
	}
	
	t = transform (t, N);
	
	if (match (t, d, N ) && !found){
		out << ROTATED_270 << endl;
		found = true;
	}
	
	t = transform (t, N);
	
	if (match (c, d, N) && !found){
		out << NO_CHANGE << endl;
		found = true;
	}
	
	t = mirror (t, N);
	
	if (match (t, d, N ) && !found){
		out << REFLECTED << endl;
		found = true;
	}
	
	for (int i=0; i < 3; i++){
		t = transform (t, N);
		if (match (t, d, N ) && !found){
			out << COMBINATION << endl;
			found = true;
		}
	}
	
	if (!found){
		out << INVALID << endl;
	}
	
	for (int i=0; i < N; ++i){
		for (int j=0; j < N; ++j){
			cout << t[i] [j] << " "; 
		}
		cout << endl;
	}
	
	
	return 0;
}
