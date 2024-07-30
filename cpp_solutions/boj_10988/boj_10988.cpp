#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string ss;
    stack<char> st;
    cin >> ss;
    int half = ss.length() / 2;
    int rest = half + ss.length() % 2;

    if (ss.length() == 1) {
        cout << "1";
        return 0;
    }

    for(int i=0;i < half; i++) st.push(ss[i]);

    for(int i=rest; i < ss.length();i++){
        if (st.top() != ss[i]) {
            cout << "0";
            return 0;
        }
        st.pop();
    }
    
    cout << "1";
}