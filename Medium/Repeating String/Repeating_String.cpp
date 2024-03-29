#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int size = s.length(), cnt = 0, leftOverCnt = 0, leftOver = n % size;
    for(int i = 0 ; i < size ; ++i){
        if(s[i] == 'a')
            cnt++;
        if(i == leftOver - 1)
            leftOverCnt = cnt;
    }

    return n / size * cnt + leftOverCnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
