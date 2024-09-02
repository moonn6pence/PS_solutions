#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N;
vector<string> arr; 

string dfs(int x, int y, int w) {
    string bit; bit = arr[x][y];

    if (w == 1) return bit;

    bool eq = true;

    for(int i=x;i<x+w;i++){
        for(int j=y;j<y+w;j++){
            if (arr[i][j] != arr[x][y]) {
                eq = false;
                break;
            }
        }
        if (!eq) break;
    }

    if (eq) return bit;

    int nw = w / 2;
    string ans = "(";

    ans += dfs(x,y,w/2);
    ans += dfs(x,y+nw,w/2);
    ans += dfs(x+nw,y,w/2);
    ans += dfs(x+nw,y+nw,w/2);

    return ans + ")";
}

int main(){
    cin >> N; arr.resize(N);
    
    for(int i=0;i<N;i++) cin >> arr[i];

    cout << dfs(0, 0, N);
}