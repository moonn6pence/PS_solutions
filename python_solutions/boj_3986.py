import sys
input = sys.stdin.readline

n = int(input())
table = [list(input().strip()) for _ in range(n)]
cnt = 0

for word in table:
    stack = []
    top = -1
    for a in word:
        if not stack:
            stack.append(a)
            top += 1
        else:
            if stack[top] == a:
                stack.pop()
                top -= 1
            else:
                stack.append(a)
                top += 1
    if not stack:
        cnt += 1

print(cnt)
