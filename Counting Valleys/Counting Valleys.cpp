#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    int sum = 0, step, valleys;
    for(int i = 0; i < n ; i++){
        step = s[i] == 'U'? 1 : -1;
        if(sum == 0)
            if(step == -1)
            valleys++;
        sum += step;
    }
    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
