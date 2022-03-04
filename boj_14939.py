import sys
input = sys.stdin.readline
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1), (0, 0)]

bulb = [[False]*10 for _ in range(10)]
tmp = [[False]*10 for _ in range(10)]

for i in range(10):
    line = list(input().strip())
    for j in range(10):
        bulb[i][j] = True if line[j] == 'O' else False


def init():
    for i in range(10):
        for j in range(10):
            tmp[i][j] = bulb[i][j]


def toggle(x, y):
    for dx, dy in dxdy:
        nx, ny = x+dx, y+dy
        if 0 <= nx < 10 and 0 <= ny < 10:
            tmp[nx][ny] = not tmp[nx][ny]


def isOff():
    for i in range(10):
        for j in range(10):
            if tmp[i][j]:
                return False
    return True


def search():
    ans = 10**9
    for state in range(1 << 10):
        cnt = 0
        init()
        for bit in range(10):
            if state & (1 << bit):
                cnt += 1
                toggle(0, bit)

        for row in range(1, 10):
            for col in range(10):
                if tmp[row-1][col]:
                    cnt += 1
                    toggle(row, col)

        if isOff():
            ans = min(ans, cnt)

    if ans < 10**9:
        return ans
    return -1


print(search())
