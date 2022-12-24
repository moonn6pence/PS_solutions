#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N;
priority_queue<pii, vector<pii>, greater<pii>> minHeap;
int parent[200000];
int lookUp[200000];
int visited[200000] = {false,};

void init(vector<int> stones){
    N = stones.size();

    fill_n(lookUp, 200000, 1);

    for (int i = 0; i < N; i++){
        minHeap.push({stones[i], i});
        parent[i] = i;
    }
}

int find(int x){
    if (parent[x] == x)
        return x;

    int p = find(parent[x]);
    parent[x] = p;

    return parent[x] = find(parent[x]);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);

    if (x != y){
        if (x < y){
            parent[y] = x;
            lookUp[x] += lookUp[y];
        }
        else{
            parent[x] = y;
            lookUp[y] += lookUp[x];
        }
    }
}

int solve(int k){
    bool flag = true;

    while(flag){
        pii minStone = minHeap.top();
        int stoneSize = minStone.first, stoneIndex = minStone.second;
        minHeap.pop();
        visited[stoneIndex] = true;

        if(stoneIndex > 0 && visited[stoneIndex - 1])
            Union(stoneIndex, stoneIndex - 1);

        if(stoneIndex < N && visited[stoneIndex + 1])
            Union(stoneIndex, stoneIndex + 1);

        if (lookUp[find(stoneIndex)] >= k)
            return stoneSize;
    }
}

int solution(vector<int> stones, int k) {
    init(stones);
    int answer = solve(k);
    return answer;
}