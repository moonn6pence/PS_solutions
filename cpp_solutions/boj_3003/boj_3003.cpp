#include <iostream>

using namespace std;

int main(){
    int k;
    int cnt[6] = {1,1,2,2,2,8};
    
    for(int i = 0; i < 6; i++){
        cin >> k;
        cnt[i] -= k;
    }
    
    for(int i = 0; i < 6; i++){
        cout << cnt[i] << ' ';
    }
    
    return 0;
}