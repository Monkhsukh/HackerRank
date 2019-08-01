#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {

    int length = s.length();
    float sqr = sqrt(length);
    int ceiling = ceil(sqr);
    int flr = floor(sqr);
    string output = "";
    flr += ceiling * flr < length ? 1 : 0;
    cout << flr << " " << ceiling<<endl;
    for(int i = 0 ; i < ceiling ; i++){
        for(int j = i; j < length ; j+= ceiling){
            output += s[j];        
        }
        output += " ";
    }

    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
