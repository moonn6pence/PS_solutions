def check(i,j,board):
    cntw=0
    cntb=0
    
    for a in range(8):
        for b in range(8):
            if (a+b)%2==0 and board[a+i][b+j]=='B':cntw+=1
            elif (a+b)%2==1 and board[a+i][b+j]=='W':cntw+=1
    for a in range(8):
        for b in range(8):
            if (a+b)%2==0 and board[a+i][b+j]=='W':cntb+=1
            elif (a+b)%2==1 and board[a+i][b+j]=='B':cntb+=1
    return min(cntw,cntb)

n,m=map(int,input().split())

board=[True]*n
total=64

for i in range(n):
    board[i]=list(input())

for i in range(n-7):
    for j in range(m-7):
        total=min(total,check(i,j,board))
print(total)
