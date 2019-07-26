#include <iostream>
#include <unordered_map>

using namespace std;

int LCSLength(string X, string Y, int n, int m ,auto &lookup){
	
	if(n == 0 || m == 0) return 0;
	x`
	string key = to_string(m) + "|" + to_string(n);
	
	if(lookup.find(key) == lookup.end()){
		if(X[n-1] == Y[m-1]){
			lookup[key] = LCSLength(X,Y,n-1,m-1,lookup) + 1;
		}
		else{
			lookup[key] = max(LCSLength(X,Y,n-1,m,lookup), LCSLength(X,Y,n,m-1,lookup));
		}
	}
	
	return lookup[key];
}

int main(){
	string X = "ABCBDAB", Y = "BDCABA";
	
	unordered_map<string, int> lookup;
	
	cout << "The length of LCS is " << LCSLength(X,Y, X.length(), Y.length(), lookup);
	
	return 0;
	
}
