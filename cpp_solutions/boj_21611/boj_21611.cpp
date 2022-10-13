#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int board[49][49];
vector<int> flatten(2401); // 2차원 배열 -> 1차원 벡터
vector<pii> stack; // <구슬번호, 갯수>
vector<int> arranged(2401); // 폭발 후 그룹핑 벡터
int bombCnt[4] = {0, 0, 0, 0}; // 0번째 더미 + 각 구슬의 폭발횟수 카운트
int dy[5] = {-1, 1, 0, 0};
int dx[5] = {0, 0, -1, 1}; // 상하좌우

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N;j++){
            cin >> board[i][j];
        }
    }
}

int flat(int y,int x){
    int r = N / 2;
    int dist = max(abs(y - r), abs(x - r));

    if (dist == 0)
        return 0;

    int ifL = (y > r - dist) && (x == r - dist);
    int ifD = !ifL && (y == r + dist);
    int ifR = !ifD && (x == r + dist);
    int ifU = !ifR && (y == r - dist);
    int dir = ifL + ifD * 2 + ifR * 3 + ifU * 4 - 1; // 좌하우상
    int idx = (2 * dist - 1) * (2 * dist - 1) + 2 * dir * dist;
    idx += ifL * (dist - r + y - 1) + ifD * (dist - r + x - 1) + ifR * (r + dist - y - 1) + ifU * (r + dist - x - 1);

    return idx;
}

void flat2D(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N;j++){
            flatten[flat(i, j)] = board[i][j];
        }
    }
}

void blizzard(int dir, int dist){
    int cef, sign, idx;
    cef = dir & 1 ? 3 : 1;
    sign = dir & 2 ? -1 : 1;

    while (dist>0){
        idx = 4 * dist * dist + sign * cef * dist;
        flatten[idx] = 0;
        dist--;
    }
}

void initStack(){
    for (int i = 0; i < N * N; i++){
        int next = flatten[i];
        if (next == 0)
            continue;
        
        if (stack.empty() || stack.back().first!=next){
            stack.push_back({next, 1});
            continue;
        } else if (stack.back().first == next){
            stack.back().second++;
        }
    }
}

void explodeStack(){
    vector<pii>::iterator it = stack.begin();
    while (!stack.empty() && it != stack.end()){
        pii elem = *it;
        if (elem.second < 4){
            it++;
            continue;
        }
        bombCnt[elem.first] += elem.second;
        it = stack.erase(it);
    }
}

bool updateStack(){
    vector<pii>::iterator it = stack.begin() + 1;
    bool isChanged = false;

    while(!stack.empty() && it != stack.end()){
        if ((*(it - 1)).first == (*it).first){
            (*(it - 1)).second += (*it).second;
            it = stack.erase(it);
            isChanged = true;
        }else{
            it++;
        }
    }
    return isChanged;
}

void explode(){
    bool isChanged = true;
    initStack();

    while (isChanged){
        explodeStack();
        isChanged = updateStack();
    }
}

void rearrange(){
    int idx = 1;

    reverse(stack.begin(), stack.end());

    while(!stack.empty()){
        if (idx >= N * N){
            stack.clear();
            break;
        }

        flatten[idx++] = stack.back().second;
        flatten[idx++] = stack.back().first;
        stack.pop_back();
    }

    while(idx<N*N){
        flatten[idx++] = 0;
    }
}

void solution(){
    int dir, dist, ans = 0;
    input();
    flat2D();
    while (M--){
        cin >> dir >> dist;
        blizzard(dir, dist);
        explode();
        rearrange();
    }
    ans = bombCnt[1] + bombCnt[2] * 2 + bombCnt[3] * 3;
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}