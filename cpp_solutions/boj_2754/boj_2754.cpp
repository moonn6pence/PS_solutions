#include <bits/stdc++.h>

using namespace std;
double score[] = {4.0, 3.0, 2.0, 1.0};

int main() {
    string g;
    cin >> g;

    if(g[0] == 'F') cout << "0.0";
    else {
        double s = score[g[0] - 'A'];
        if(g[1] == '+') s+=0.3;
        else if(g[1] == '-') s-=0.3;
        cout << fixed;
        cout.precision(1);
        cout << s;
    }
}