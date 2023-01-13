#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[100][100] = {false,};
string graph[100];
pii src, dest;

void init(){
    fill(&visited[0][0], &visited[99][100], false);
}

void input(){
    int tc;
    cin >> tc;
    for (int i = 0; i < 100; i++){
        cin >> graph[i];
        for (int j = 0; j < 100; j++){
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
            
            if (nx < 0 || ny < 0 || nx > 99 || ny > 99) continue;
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