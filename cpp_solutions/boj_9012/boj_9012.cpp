#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    string ans[2] = {"NO\n","YES\n"};

    while(T--){
        string ss; cin >> ss;
        int vps = 1;
        stack<bool> st;

        for(char c : ss){
            if (c == '(') st.push(1);
            else {
                if (st.empty()) {
                    vps = 0;
                    break;
                }
                else st.pop();
            } 
        }

        cout << ans[(vps && st.empty())];
    }
}