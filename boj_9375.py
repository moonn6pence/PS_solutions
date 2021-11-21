import sys
input = sys.stdin.readline

t = int(input())
while t:
    ans = 1
    n = int(input())
    closet = dict()
    for _ in range(n):
        x, category = input().split()
        if category in closet:
            closet[category] += 1
        else:
            closet[category] = 1
    for value in closet.values():
        ans *= value+1
    print(ans-1)
    t -= 1
