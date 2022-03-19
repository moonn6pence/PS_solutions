import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
s = input().rstrip()
cnt = 0
state = 0
i = 1

while i < m-1:
    if s[i-1] == 'I' and s[i] == 'O' and s[i+1] == 'I':
        state += 1
        if state == n:
            state -= 1
            cnt += 1
        i += 1
    else:
        state = 0
    i += 1

print(cnt)
