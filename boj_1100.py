cnt = 0
board = [input() for i in range(8)]
for i in range(8):
    for j in range(8):
        if (i+j) % 2 == 0 and board[i][j] == 'F':
            cnt += 1
print(cnt)
