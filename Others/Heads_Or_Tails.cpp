#include <iostream>
#include <map>
using namespace std;

/**
	author: Munkhsukh
	date: 2018-05-25 10:24pm
	name: Heads or tails
*/

int main ()
{
	// variables
	map<int,int> seqMap;
	string input;
	int length;
	int count = 0;
	int maxT = 0;
	int maxH = 0;
	int maxFreq =  0;
	int maxFreqCnt =  0;
    
    // input
	cin >> length;
	cin >> input;
	
	// looping array
	for(int i = 0 ; i < length; i++) {
		count++;
		if(i != length-1)	// is it last item?
			if(input[i] == input[i+1])	// is next item same?
				continue;
		
		if(input[i] == 'T') {	// if item is tail, just find max length sequence
			if(maxT < count)
				maxT = count;
		}
		else{
			if(seqMap.find(count) == seqMap.end())	// find sequence length from map
				seqMap.insert(make_pair(count,1));	// if not, add sequence length to map
			else
				seqMap[count]++;	// if found, the occurrence is added by one 
				
			if(maxH < count)	// find the longest head sequence
				maxH = count;
				
			if(maxFreqCnt < seqMap[count]){	// check max number sequence frequency 
				maxFreq = count;
				maxFreqCnt = seqMap[count];
			}
			else if(maxFreqCnt == seqMap[count]){	// if number of the sequence frequency equal max number frequency, choose the longest sequence
				if(maxFreq < count)
					maxFreq = count;
			}
		}	
		count = 0;
	}
	
	// print
	cout<<seqMap[2]<<endl;
	cout<<maxH<<' '<<maxT<<endl;
	cout<<maxFreq;
	
	return 0;
}

