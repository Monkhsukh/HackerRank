#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

string DivitionToString(int a, int b){
	string output;
	output.append(to_string(a/b));
	
	int mod = a%b;
	
	if(mod & 1){
		output.append(".");
		string mystring = "";
		
		do{
			int div = (mod*10) / b;
			mod = (mod*10) % b;
			size_t position = mystring.find((char)(div + 48));
			if(position == -1){
				mystring+=((char)(div+48));
			}else{
				output.append(mystring.substr(0,position));
				output.append("(" + mystring.substr(position)+ ")");
				return output;
			}
		}
		while((mod != 0));
		output.append(mystring);
	}
		
	return output;
}

int main(){

	ifstream inFile;
	inFile.open("input.in");
	if(!inFile){
		cout<<"Unable to open file";
		exit(1);
	}
	
	int inputCnt;
	inFile >> inputCnt;
	
	while(inputCnt!=0){
		int a, b;
		inFile >> a;
		inFile >> b;
		
		cout << a<< "/"<<b<<"="<<DivitionToString(a, b)<<endl;
		
		inputCnt--;
	} 
	
	inFile.close();
	return 0;
}
