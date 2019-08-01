#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int size = w.size();
    stack<char> stk;
    bool possible = false;
    for(int i = size - 2; i >= 0 ; i-- ){
        stk.push(w[i+1]);
        if(w[i] < w[i+1]){
            int j = size-1;
            bool isSwapped = false;
            while(!stk.empty()){
                w[j] = stk.top();
                if(!isSwapped)
                    if(w[i] > w[j]){
                        char temp = w[i];
                        w[i] = w[j+1];
                        w[j+1] = temp;
                        isSwapped = true;
                    }
                    if(w[i] == w[j]){
                        char temp = w[i];
                        w[i] = w[j+1];
                        w[j+1] = temp;
                        isSwapped = true;
                    }
                stk.pop();
                j--;
            }
            if(!isSwapped){
                char temp = w[i];
                w[i] = w[i+1];
                w[i+1] = temp;
            }
            possible = true;
            break;
        }
    }

    return possible ? w : "no answer";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
