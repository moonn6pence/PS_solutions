#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, string> pis;

int N;
vector<vector<string>> inputs;
vector<string> result;

void input(){
    cin >> N;

    for (int i = 0; i < N; i++){
        vector<string> line;
        string food;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> food;
            line.push_back(food);
        }
        inputs.push_back(line);
    }

    inputs.push_back(vector<string>({""}));
    N++;

    sort(inputs.begin(), inputs.end());
    reverse(inputs.begin(), inputs.end());
}

void solve(){
    vector<string> stack(inputs[0].begin(), inputs[0].end());

    for (int i = 1; i < N; i++){
        int idx = 0, top = stack.size() - 1;

        while (stack[idx] == inputs[i][idx]){
            idx++;
        }

        while(top >= idx){
            string str = stack[top];
            stack.pop_back();

            int tmp = top;
            while (tmp--){
                str = "--" + str;
            }
            result.push_back(str);

            top--;
        }

        while(idx < inputs[i].size()){
            stack.push_back(inputs[i][idx++]);
        }
    }

    reverse(result.begin(), result.end());
}

void output(){
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<'\n';
    }
}

void solution(){
    input();
    solve();
    output();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}