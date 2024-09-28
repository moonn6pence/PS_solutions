#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int N,L,R;
int A[50][50];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

void input(){
    cin >> N >> L >> R;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][j];
}

void bfs(int visited[][50],vector<pii>& info, int sx, int sy, int unn){
    int cnt = 1, sum = A[sx][sy];

    queue<pii> order;
    order.push({sx,sy});
    visited[sx][sy] = unn;

    while(!order.empty()){
        int x,y; tie(x,y) = order.front();
        order.pop();

        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];

            if (nx<0||nx>=N||ny<0||ny>=N) continue;
            if (visited[nx][ny] != -1) continue;

            int diff = abs(A[x][y] - A[nx][ny]);
            if (L > diff || diff > R) continue;

            order.push({nx,ny});
            visited[nx][ny] = unn;
            sum += A[nx][ny];
            cnt++;
        }
    }

    info.push_back({sum,cnt});
}

void solution(){

    int day = 0;

    while (true){
        bool flag = false;
        int unn = 0;
        vector<pii> info;
        int visited[50][50];
        fill(&visited[0][0], &visited[49][50], -1);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if (visited[i][j] == -1){
                    bfs(visited,info,i,j,unn++);
                }
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int sum,cnt; tie(sum,cnt) = info[visited[i][j]];
                if (cnt == 1) continue;

                A[i][j] = sum/cnt;
                flag = true;
            }
        }

        if (flag) day++;
        else break;
    }

    cout << day;
}

int main(){
    input();
    solution();
}