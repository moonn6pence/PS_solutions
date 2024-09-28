#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> v(N);
    vector<int> nge(N, -1);
    stack<int> st;


    for(int i=0;i<N;i++) {
        cin >> v[i];

        while (!st.empty() && v[st.top()] < v[i]) {
            nge[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }

    for(int it : nge) cout << it << " ";
}