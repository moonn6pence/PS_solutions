#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    for(char c : s){
        if(!isalpha(c))cout<<c;
        else printf("%c",((c-(c<97?52:84))%26+(c<97?65:97)));
    }
}