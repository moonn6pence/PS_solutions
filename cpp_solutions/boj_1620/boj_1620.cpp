#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<string> book;
    book.resize(N+1);
    unordered_map<string, int> num;

    for(int i=1;i<=N;i++) {
        cin >> book[i];
        num[book[i]] = i;
    }

    for(int i=0;i<M;i++){
        string query;
        cin >> query;
        if (isdigit(query[0])) cout << book[stoi(query)] << '\n';
        else cout << num[query] << '\n';
    }
}