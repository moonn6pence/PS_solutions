#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> pii;
vector<pair<pii,pii>> sq;
int M, N, K, graph[100][100];
bool visited[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

bool is_sqaure(int x, int y){

    for(pair<pii,pii> it : sq){
        pii p1,p2; tie(p1,p2) = it;
        if (p1.first <= x && p1.second <= y && x < p2.first && y < p2.second) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    cin >> M >> N >> K;

    for(int i=0;i<K;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        sq.push_back({{b,a},{d,c}});
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if (!is_sqaure(i,j) && !visited[i][j]){
                int tmp = 0;

                queue<pii> q; q.push({i,j});
                visited[i][j] = true;

                while(!q.empty()){
                    int x,y; tie(x,y) = q.front();
                    q.pop();
                    tmp++;

                    for(int d=0;d<4;d++){
                        int nx = x + dx[d], ny = y + dy[d];

                        if (nx < 0 || nx >= M || ny  < 0 || ny >= N) continue;
                        if (visited[nx][ny] || is_sqaure(nx,ny)) continue;

                        q.push({nx,ny}); visited[nx][ny] = true;
                    }
                }

                v.push_back(tmp);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int it : v) cout << it << ' ';
}