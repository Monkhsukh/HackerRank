#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n = container[0].size();
    int arr[n] = {0};
    unordered_map<int,int> map;

    for(auto i = container.begin(); i != container.end(); i++){
        int sum = 0;
        int k = 0;
        for(auto j = (*i).begin(); j != (*i).end(); j++){
            sum += *j;
            arr[k] += *j;
            k++;
        }
        map.find(sum) == map.end() ? map[sum] = 1 : map[sum]++;
    }

    for(int i = 0 ; i < n ; i++){
        auto it = map.find(arr[i]);
        if(it != map.end()){
            if(it->second == 1)
                map.erase(it);
            else
                it->second--;
        }
        else
            return "Impossible";
    }
    // for(auto i = map.begin(); i != map.end(); i++){
    //     cout<<i->first<<":"<<i->second<<endl;
    // }

    return map.size() == 0 ? "Possible" : "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
