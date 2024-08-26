#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int graph[100][100];
bool visited[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(){

    int N; cin >> N;
    int rmin=100,rmax=1,ans=1;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> graph[i][j];
            rmin = min(rmin, graph[i][j]);
            rmax = max(rmax, graph[i][j]);
        }
    }

    for(int r=rmin; r<rmax; r++){

        int tmp=0;
        fill(&visited[0][0],&visited[99][100],false);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if (graph[i][j] > r && !visited[i][j]){
                    tmp++;
                    queue<pii> q;
                    q.push({i,j});
                    visited[i][j] = true;

                    while(!q.empty()){
                        int x,y; tie(x,y) = q.front();
                        q.pop();

                        for(int d=0;d<4;d++){
                            int nx = x + dx[d], ny = y + dy[d];

                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (graph[nx][ny] <= r || visited[nx][ny]) continue;

                            q.push({nx,ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }

        ans = max(ans, tmp);
    }

    cout << ans;
}