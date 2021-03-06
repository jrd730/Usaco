/*
ID: jrd7301
PROG: milk2
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

int highestEnd = 0;

struct interval
{
	int start, end;
};

bool operator < ( interval i1,interval i2 ) { return i1.start < i2.start;}

int main ()
{
	ifstream in ("milk2.in");
	ofstream out ("milk2.out");
	
	int farmerCount;
	in >> farmerCount;
	
	//schedule holds all of the work start/stop times for farmers
	vector <interval> schedule;
	schedule.resize (farmerCount);
	
	for ( int i=0; i<farmerCount; i++ )
	{
		interval I;
		in >> I.start >> I.end;
		//if ( I.end > highestEnd ) highestEnd = I.end;
		schedule[i] = I;
	}
	
	//cout << highestEnd << endl;
	
	//sort schedule by order of start time
	sort ( schedule.begin(), schedule.end() ); 
	
	int longestWorkStreak = 0, longestIdleStreak = 0;

	//find longest work streak
	//longest work streak could begin with any farmer 
	for( int i = 0; i < farmerCount; i++ )
	{
		int streakStart = schedule[i].start;
		int streakStop = schedule[i].end;
		
		//check if this farmer has worked longer than greatest streak
		if ( schedule[i].end - schedule[i].start > longestWorkStreak ) 
			longestWorkStreak = schedule[i].end - schedule[i].start ; 
		
		//longest work streak could end with any farmer who arrives before former farmer leaves
		for ( int j = i + 1; j < farmerCount; j++ )
		{
			//farmer arrives during former farmers shift
			if ( schedule[j].start <= streakStop )
			{
				//farmer stays after former farmer
				if ( schedule[j].end > streakStop )
				{
					streakStop = schedule[j].end;
					
					//if current streak is greater than max so far, make it the new max
					if ( streakStop - streakStart > longestWorkStreak ){
				 		longestWorkStreak = streakStop - streakStart;
				 	}
				}
			}
			//this streak ended
			else 
			{
				break;
			}
		}
	}
	
	
	//find the longest idle gap between any two shifts
	{
		int i = 0;
		int idleStart = schedule[i].end;
		int idleStop = schedule[i].end;
		int idleTime = 0;
		
		for ( int j = i + 1; j < farmerCount; j++ )
		{
			//next shift overlaps
			if (schedule[j].start < schedule[i].end && schedule[j].end <= schedule[i].end)
			{
				//ignore
			}
			
			//next shift overlaps and extends 
			else if (schedule[j].start <= schedule[i].end && schedule[j].end > schedule[i].end)
			{
				idleStart = schedule[j].end;
				idleStop = schedule[j].end;
				
				i = j;
			}
			
			//next shift leaves a gap before
			else if (schedule[j].start > schedule[i].end)
			{
				idleStop = schedule[j].start;
				idleTime = idleStop - idleStart;
				if ( idleTime > longestIdleStreak) longestIdleStreak = idleTime;
				
				idleStart = schedule[j].end;
				idleStop = schedule[j].end;
				
				i = j;
			}
		}
	}
	
	out << longestWorkStreak << " " << longestIdleStreak << endl;
	return 0;
}
