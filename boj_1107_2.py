import sys
input = sys.stdin.readline


def check(num):
    num = list(str(num))
    for i in num:
        if i in b:
            return False
    return True


n = int(input())
m = int(input())
b = list(input().split())
ans = abs(n-100)
for i in range(1000001):
    if check(i):
        ans = min(ans, len(str(i))+abs(i-n))
print(ans)
