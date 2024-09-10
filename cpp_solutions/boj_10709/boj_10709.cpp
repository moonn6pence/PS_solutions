#include <iostream>
#include <string>

using namespace std;

int main(){
    int H,W; cin >> H >> W;
    char area[100][100];
    int time[100][100];

    fill(&time[0][0],&time[99][100],-1);

    for(int i=0;i<H;i++){
        string tmp; cin >> tmp;
        for(int j=0;j<W;j++) {
            area[i][j] = tmp[j];
        }
    }

    for(int i=0;i<H;i++){

        int w = 0, c = -1;

        while (w < W){
            if (area[i][w] != 'c') {
                if (c == -1) {
                    w++; continue;
                }
                time[i][w] = ++c;
            } else time[i][w] = c = 0;
            w++;
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) {
            cout << time[i][j] << ' ';
        }
        cout << '\n';
    }
}