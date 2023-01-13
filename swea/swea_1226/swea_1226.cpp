#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[16][16] = {false,};
string graph[16];
pii src, dest;

void init(){
    fill(&visited[0][0], &visited[15][16], false);
}

void input(){
    int tc;
    cin >> tc;
    for (int i = 0; i < 16; i++){
        cin >> graph[i];
        for (int j = 0; j < 16; j++){
            if (graph[i][j] == '2') src = {i, j};
            else if (graph[i][j] == '3') dest = {i, j};
        }
    }
}

bool solve(){
    queue<pii> order;
    order.push(src);
    visited[src.first][src.second] = true;
    
    while (!order.empty()){
        int x = order.front().first, y = order.front().second;
        order.pop();
        
        if (x == dest.first && y == dest.second) return true;
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx > 15 || ny > 15) continue;
            if (visited[nx][ny] || graph[nx][ny] == '1') continue;
            
            order.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    
    return false;
}

int main()
{
	int test_case;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        input();
        init();
        cout << '#' << test_case << ' ' << solve() << '\n';
	}
	return 0;
}