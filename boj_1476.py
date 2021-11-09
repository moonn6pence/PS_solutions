e, s, m = map(lambda x: int(x)-1, input().split())
for n in range(e, 15*28*19+1, 15):
    if n % 28 == s and n % 19 == m:
        print(n+1)
        break
