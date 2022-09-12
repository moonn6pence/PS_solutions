#include <string>

using namespace std;

int getDivisor(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return i;
    }
    return x;
}

int solution(int n) {
    return getDivisor(n-1);
}