#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    int T; cin >> T;

    while(T--){
        int N,M,K,cnt=0,graph[50][50];
        bool visited[50][50];
        fill(&graph[0][0],&graph[49][50],0);
        fill(&visited[0][0],&visited[49][50],false);
        cin >> M >> N >> K;

        for(int i=0;i<K;i++){
            int x,y; cin >> y >> x;
            graph[x][y] = 1;
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(graph[i][j] == 1 && !visited[i][j]){
                    queue<pii> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    cnt++;

                    while(!q.empty()){
                        int x,y; tie(x,y) = q.front();
                        q.pop();

                        for(int d=0;d<4;d++){
                            int nx = x + dx[d], ny = y + dy[d];

                            if (nx < 0 || nx >= N || ny < 0 || ny >= M || !graph[nx][ny] || visited[nx][ny]) continue;

                            q.push({nx,ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';
    }
}