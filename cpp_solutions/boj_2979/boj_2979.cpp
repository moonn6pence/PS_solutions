#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int p[4], sum = 0, min_in = 100, max_out = 0;
    vector<int> cnt(100,0);

    p[0] = 0;
    cin >> p[1] >> p[2] >> p[3];

    for(int i = 0; i < 3; i++){
        int start,end;
        cin >> start >> end;

        min_in = min(min_in, start);
        max_out = max(max_out, end);
        for(int j = start; j < end; j++) cnt[j]++;
    }

    for(int i = min_in; i < max_out; i++) sum += p[cnt[i]] * cnt[i];

    cout << sum;
}