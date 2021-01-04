import sys

board=[list(map(int,input().split())) for _ in range(9)]
blank=[(i,j) for i in range(9) for j in range(9) if board[i][j]==0]

def ans(n):
    if n==len(blank):
        for row in board:print(*row)
        sys.exit(0)
    
    x=blank[n][0]
    y=blank[n][1]
    dx=(x//3)*3
    dy=(y//3)*3
    num_list=[False]+[True]*9
    
    for i in range(9):
        if board[x][i]:num_list[board[x][i]]=False
        if board[i][y]:num_list[board[i][y]]=False
    for i in range(dx,dx+3):
        for j in range(dy,dy+3):
            if board[i][j]:num_list[board[i][j]]=False

    possible_list=[i for i,k in enumerate(num_list) if k]

    for t in possible_list:
        board[x][y]=t
        ans(n+1)
        board[x][y]=0

ans(0)
