#include <bits/stdc++.h>
using namespace std;
int N,a,c,b,d;
int main(){
    cin>>N>>a>>c>>b>>d;
    int dist,len=2*N-1,m=N-1;
    for (int x=a;x<=b;x++) {
        for (int y=c;y<=d;y++) {
            int dist=abs(m-x%len)+abs(m-y%len);
            cout<<(dist>(N-1)?'.':(char)('a'+dist%26));
        }
        cout<<'\n';
    }
}