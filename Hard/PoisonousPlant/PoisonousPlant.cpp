#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct ele {
    int index;
    int cnt;
};

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    stack<ele> s;
    stack<ele> pr;
    int glob_max = 0;
    int stk_lim = INT_MIN;

    for(int i = 1; i < p.size(); i++){
        
        // A < B
        if(p[i-1] < p[i]){
            while(s.size() > 0){
                ele top = s.top();
                if(top.index < p[i-1]){
                    s.push({p[i-1], 1});
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.size() == 0){
                s.push({p[i-1], 1});
                stk_lim = 1;
                glob_max = max(glob_max, stk_lim);
            } 
        }else{
            if(s.size() != 0){
                while(s.size() > 0 && s.top().index >= p[i]) 
                    s.pop();
                if(s.size() > 1){
                    while(stk_lim == s.top().cnt && s.size() > 1) s.pop();
                }
                    
                if(s.size() == 0){
                    s.push({p[i-1], 1});
                    stk_lim = 1;
                }else{
                    ele top = s.top(); s.pop();
                    if(s.size() > 1){
                        while(top.cnt == s.top().cnt && s.size() > 1){
                            top = s.top(); s.pop();
                        } 
                    }
                    top.cnt++;
                    s.push(top);
                    if(s.size() == 1) stk_lim = top.cnt;
                    glob_max = max(glob_max, stk_lim);
                    //cout<<"glob_max:"<<glob_max<<endl;
                }
            }
        }

        // cout<< "size:" << s.size()<<endl;
        // while(!s.empty()){
        //     ele top = s.top(); s.pop();
        //     cout << p[i] << "~" << top.index << ":" << top.cnt << endl;
        //     pr.push(top);
        // }
        // while(!pr.empty()){
        //     ele top = pr.top(); pr.pop();
        //     s.push(top);
        // }
        // cout<<endl;

    }
    return glob_max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
