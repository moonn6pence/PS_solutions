import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    num = int(input())
    base, cnt = 5, 0
    while base <= num:
        cnt += num//base
        base *= 5
    print(cnt)
