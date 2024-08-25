#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int cnt = 0, N; cin >> N;

    while (N--){
        string ss;
        cin >> ss;
        
        if (ss.length() % 2 != 0) continue;

        stack<char> st;

        for(char c : ss){
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }
        if (st.empty()) cnt++;
    }

    cout << cnt;
}