#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char table[1023][2045];

void fractal(int row,int col,int step){
  table[row][col] = '*';
  if (step == 1)
    return;
  int height = (1 <<step)-1;
  bool dir = step % 2;

  int front = col, rear = col;
  for (int i = 1; i < height;i++){
    if(dir)
      row++;
    else
      row--;
    front--;
    rear++;
    table[row][front] = '*';
    table[row][rear] = '*';
  }
  for (int j = front + 1; j < rear;j++){
    table[row][j] = '*';
  }
  if(dir)
    row--;
  else
    row++;
  fractal(row, col, step - 1);
}

int main() {
  fastio;
  int n; cin >> n;

  int height = (1 << n) - 1;
  int width = (1 << (n + 1)) - 3;
  for (int i = 0; i < height;i++){
    for (int j = 0; j < width;j++){
      table[i][j] = ' ';
    }
  }

  bool dir = n % 2;
  int row=0, col;
  if(!dir)
    row = (1 << n) - 2;
  col = (1 << n) - 2;
  fractal(row,col,n);
  
  if(dir){
    for (int i = 0; i < height;i++){
      for (int j = 0; j < col+i+1;j++){
        cout << table[i][j];
      }
      cout <<'\n';
    }
  }else{
    for (int i = 0; i < height;i++){
      for (int j = 0; j < width-i;j++){
        cout << table[i][j];
      }
      cout <<'\n';
    }
  }
}
