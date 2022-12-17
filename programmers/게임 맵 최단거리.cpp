#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int bfs(vvi maps){

    int n = maps.size(), m = maps[0].size();

    vvi visited(n, vector<int>(m, 0));
    queue<pii> order;

    order.push({0, 0});

    while (!order.empty()){
        pii cur = order.front();
        order.pop();
        int curx = cur.first, cury = cur.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i], ny = cury + dy[i];
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 0 || visited[nx][ny] != 0) continue;

            visited[nx][ny] = visited[curx][cury] + 1;
            if(nx == n-1 && ny == m-1)
                return visited[nx][ny] + 1;
            order.push({nx, ny});
        }
    }

    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = bfs(maps);
    return answer;
}