/*
ID: jrd7301
PROG: barn1
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
	ifstream in ("barn1.in");
	ofstream out ("barn1.out");
	vector <int> c;
	int M, S, C;//max boards, stalls, cows in stalls
	int boardsused = 0;
	in >> M >> S >> C;
	c.resize (C);
	for (int i=0; i<C; ++i)	in >> c[i];
	sort ( c.begin(), c.end() );//index 0 is the first occupied stall
	
	int boarded = 0;//how many blocked stalls, occupied or not
	int blocked = 0;//how many cows are blocked in their stalls
  int maxblength = 1;
  int boardsleft;
  while (blocked < C){
    boardsleft = M;
    for (int i=0; i<C; i++){
      //cout << c[i] << endl;
      if (blocked < C && boardsleft > 0){
        blocked++;
        if (i < C-1){
          int board = c[i+1] - c[i]; 
          if (board <= maxblength){
            boarded+=board;
            cout << "extending board from " << c[i] << " to " << c[i+1] << endl;
          }
          else{
            boardsleft--;
            boarded++;
            cout << "stopping board at " << c[i] << endl;
          }
        }
        else{
          boardsleft--;
          boarded++;
          boardsused = M - boardsleft;
          cout << "stopping final board at " << c[i] << endl;
        }
      }
      else{
        blocked = 0;
        boarded = 0;
        maxblength++;
        cout << "resetting with new max board length: " << maxblength << endl;
        break;
      }
    } 
  }
  while (boardsleft > 0){
    int splitblength = maxblength;        
    for (int j=0; j<C-1; j++){
      int board = c[j+1] - c[j];
      if (board >= splitblength && board <= maxblength && boardsleft > 0){
        boarded -= board-1;
        cout << "splitting board between: " << c[j] << " and " << c[j+1] << endl;
        boardsused++;
        boardsleft--;
      }
    }
    splitblength--;
    if (splitblength == 0)break;
  }
  cout << "all cows are now blocked" << endl;
	cout << "Total boarded stalls: " << boarded << endl;
	cout << "Used " << boardsused << " out of " << M << " boards" << endl;
	out << boarded << endl;
	return 0;
}
