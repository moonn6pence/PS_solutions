price = [0]+list(map(int, input().split()))
mark = [0]*101
ans = 0
for _ in range(3):
    s, e = map(int, input().split())
    for t in range(s, e):
        mark[t] += 1
for i in range(101):
    ans += price[mark[i]]*mark[i]
print(ans)
