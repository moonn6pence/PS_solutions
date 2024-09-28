#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1){
        string ss; getline(cin,ss);
        if (ss == ".") break;

        stack<char> st; bool ret = true;

        for(char c : ss){
            if (c == '(') st.push('(');
            else if (c == '[') st.push('[');
            else if (c == ')') {
                if (st.empty() || st.top() != '('){
                    ret = false;
                    break;
                }
                st.pop();
            } else if (c == ']'){
                if (st.empty() || st.top() != '['){
                    ret = false;
                    break;
                }
                st.pop(); 
            }
        }

        if (st.empty() && ret) cout << "yes\n";
        else cout << "no\n";
    }
}