#include <iostream>
#include <memory.h>
#include <set>
#include <vector>

using namespace std;

int N;
vector<int> rus;
vector<int> kor;

void input(vector<int> &rus, vector<int> &kor){
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        rus.push_back(tmp);
    }
    for (int i = 0; i < N; i++){
        cin >> tmp;
        kor.push_back(tmp);
    }
}

int greedy(const vector<int> &rus,const vector<int> &kor){
    int win = 0;
    multiset<int> rating(kor.begin(), kor.end());
    for (int i = 0; i < N; i++){
        if(*rating.rbegin()<rus[i]){
            rating.erase(rating.begin());
        }else{
            rating.erase(rating.lower_bound(rus[i]));
            win++;
        }
    }

    return win;
}

void solution(){
    int tc;
    cin >> tc;
    while(tc--){
        vector<int> rus;
        vector<int> kor;
        input(rus,kor);
        cout << greedy(rus,kor) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}