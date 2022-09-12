#include <string>

using namespace std;

bool isEven(int num){
    if(num&1) return false;
    return true;
}

string solution(int num) {
    return isEven(num)?"Even":"Odd";
}