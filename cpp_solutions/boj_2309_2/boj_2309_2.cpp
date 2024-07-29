#include <bits/stdc++.h>

using namespace std;

int find_xmans(vector<int>& v, int cnt, int sum, int surplus, int bit, int from){
    if (cnt == 2 && sum == surplus) return bit;

    int result = -1;

    for(int i = from; i < 9; i++){
        if (bit & (1 << i)) continue;
        result = find_xmans(v, cnt + 1, sum + v[i], surplus, bit | (1 << i), i + 1);
        if (result != -1) return result;
    }

    return -1;
}

void print_dwarfs(vector<int>& v, int xmans) {
    for(int i = 0; i < 9; i++){
        if (xmans & (1 << i)) continue;
        cout << v[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    int surplus = 0;
    v.resize(9);
    for(int i=0;i<9;i++) {
        cin >> v[i];
        surplus += v[i]; 
    }
    surplus -= 100;
    sort(v.begin(), v.end());

    print_dwarfs(v, find_xmans(v, 0, 0, surplus, 0, 0));
}