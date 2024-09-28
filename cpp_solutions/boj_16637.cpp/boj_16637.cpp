#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int N;
vector<ll> num;
vector<char> op;

void input(){
    cin >> N;
    string ss; cin >> ss;

    for(char c : ss) {
        if ('0' <= c && c <= '9') num.push_back((ll)(c - '0'));
        else op.push_back(c);
    }
}

int compute(ll a, char ops, ll b){
    ll ret;

    if (ops == '+') ret=a+b;
    else if(ops == '-') ret=a-b;
    else ret=a*b;

    return ret;
}

ll calculate(vector<ll> &arr, vector<char> &ops){
    ll ret = arr[0];

    for(int i=1,j=0;i<arr.size();i++,j++) ret = compute(ret,ops[j],arr[i]);

    return ret;    
}

int solve(int bit, int cur){
    if (cur*2+1 >= N) {
        vector<ll> tmp_num;
        vector<char> tmp_op;

        tmp_num.push_back(num[0]);

        for (int i=0; i*2+1 < N;i++){
            if (bit & (1 << i)){
                tmp_num.pop_back();
                tmp_num.push_back(compute(num[i],op[i],num[i+1]));
            } else {
                tmp_num.push_back(num[i+1]);
                tmp_op.push_back(op[i]);
            }   
        }

        return calculate(tmp_num, tmp_op);
    }

    return max(solve(bit, cur+1), solve(bit|(1<<cur), cur+2));
}

void solution(){
    input();
    cout << solve(0,0);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solution();
}