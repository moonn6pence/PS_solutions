n, m = map(int, input().split())
move = [(2, 1), (1, 2), (-2, 1), (-1, 2)]
cnt = 0

if n == 1:
    cnt = 1
elif n == 2:
    cnt = min(3, (m-1)//2)+1
else:
    if m <= 6:
        cnt = min(4, m)
    else:
        cnt = m-2
print(cnt)
