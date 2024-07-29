#include <bits/stdc++.h>

using namespace std;

void input(vector<int> &v) {
    int tmp;
    for(int i=0;i<9;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
}

void print(vector<int> v, int x1, int x2) {
    for(int i = 0; i < 9; i++) {
        if (i == x1 || i == x2) continue;
        cout << v[i] << '\n';
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> heights;
    int sum = 0,surplus;

    input(heights);
    sort(heights.begin(), heights.end());

    for(int i=0;i<9;i++) sum += heights[i];
    surplus = sum - 100;

    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 9; j++){
            if((heights[i] + heights[j]) == surplus) {
                print(heights,i,j);
                return 0;
            }
        }
    }

}