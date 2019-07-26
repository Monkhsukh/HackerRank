#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    // total
    int total = 0, up, down, left, right;
    up = (n - r_q);
    down = r_q - 1;
    right = (n - c_q);
    left = c_q -1;
    
    cout<<"up"<<up<<endl;
    cout<<"down"<<down<<endl;
    cout<<"left"<<left<<endl;
    cout<<"right"<<right<<endl;

    //up | left 
    total+= (up > left ? left : up);
    cout<<"up | left "<<(up > left ? left : up)<<endl;
    //up | right 
    total+= (up > right ? right : up);
    cout<<"up | right "<<(up > right ? right : up)<<endl;
    //down | left 
    total+= (down > left ? left : down);
    cout<<"down | left "<<(down > left ? left : down)<<endl;
    //down | right
    total+= (down > right ? right : down);
    cout<<"down | right "<<(down > right ? right : down)<<endl;
    
    total+=(up + down + left + right);
    cout <<"total:"<< total<<endl;

    int minus = 0;
    int min_right, min_left, min_up, min_down, min_upright, min_upleft, min_downright, min_downleft;
    min_right = min_left = min_up = min_down = min_upright = min_upleft = min_downright = min_downleft = 0;

    for (vector<vector<int>>::iterator i = obstacles.begin(); i != obstacles.end(); ++i){
        vector<int> obstacle = *i;
        //right 
        if(obstacle[0] == r_q && obstacle[1] > c_q){
            int right = (n - obstacle[1] + 1);
            if(right > min_right)
                min_right = right;
            //cout<<"right"<<(n - obstacle[1] + 1)<<endl;
        }
            
        //left
        if(obstacle[0] == r_q && obstacle[1] < c_q){
            if(obstacle[1] > min_left)
                min_left = obstacle[1];
            //cout<<"left"<<obstacle[1]<<endl;
        }
            
        //up 
        if(obstacle[1] == c_q && obstacle[0] > r_q){
            int up = (n - obstacle[0] + 1);
            if(up > min_up)
                min_up = up;
            //cout<<"up"<<(n - obstacle[0] + 1)<<endl;
        }
            
        //down
        if(obstacle[1] == c_q && obstacle[0] < r_q){
            if(obstacle[0] > min_down)
                min_down = obstacle[0];
            //cout<<"up"<<(obstacle[0])<<endl;
        }
        
        int diffRow = obstacle[0] - r_q;
        int diffCol = obstacle[1] - c_q;
        if(diffRow == diffCol){
            if(diffRow > 0){
                //up right
                int upright = obstacle[0] > obstacle[1] ? (n - obstacle[0]+1) : (n - obstacle[1]+1);
                if(upright > min_upright)
                    min_upright = upright;
                //cout<<"up right"<<(obstacle[0] > obstacle[1] ? (n - obstacle[0]+1) : (n - obstacle[1]+1))<<endl;
            }
            else{
                //down left
                int downleft = obstacle[0] < obstacle[1] ? obstacle[0] : obstacle[1];
                if(downleft > min_downleft)
                    min_downleft = downleft;
                cout<<"down left"<<(obstacle[1] ? obstacle[0] : obstacle[1])<<endl;
            }
        }

        if(diffRow == diffCol*(-1)){
            if(diffRow > 0){
                //up left
                int upleft = (n-obstacle[0]+1) > obstacle[1] ? obstacle[1] : (n- obstacle[0]+1);
                if(upleft > min_upleft)
                    min_upleft = upleft;
                cout<<"up left"<<((n-obstacle[0]+1) > obstacle[1] ? obstacle[1] : (n- obstacle[0]+1))<<endl;
            }
            else{
                //down right
                int downright = (n-obstacle[1]+1) > obstacle[0] ? obstacle[0] : (n- obstacle[1]+1);
                if(downright > min_downright)
                    min_downright = downright;
                cout<<"down right"<<((n-obstacle[1]+1) > obstacle[0] ? obstacle[0] : (n- obstacle[1]+1))<<endl;
            }
                
        }
        //cout<< <<endl;
    }
    //cout<<"minus:"<<minus<<endl;
    return total - min_right - min_left - min_up - min_down - min_upleft - min_upright - min_downleft - min_downright;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
