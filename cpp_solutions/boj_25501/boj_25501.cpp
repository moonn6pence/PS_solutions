#include <iostream>
#include <string>

using namespace std;
int cnt;

int recursion(string* s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if((*s)[l] != (*s)[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string* s){
    return recursion(s, 0, (*s).length() - 1);
}

void solution(){
    int T;
    cin >> T;

    while (T--){
        cnt = 0;
        string word;
        cin >> word;
        cout << isPalindrome(&word) << " " << cnt << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}