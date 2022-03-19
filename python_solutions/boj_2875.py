n, m, k = map(int, input().split())

cnt = 0

while True:
    if n > 1 and m > 0:
        cnt += 1
        n -= 2
        m -= 1
    else:
        break

if n > 0:
    k -= n
if m > 0:
    k -= m

if k > 0:
    cnt -= (k+2)//3

print(cnt)
