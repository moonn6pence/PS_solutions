n = int(input())
meetings = [tuple(map(int, input().split())) for _ in range(n)]
meetings.sort(key=lambda x: (x[1], x[0]))
cnt, prev = 0, 0

for start, end in meetings:
    if start >= prev:
        cnt += 1
        prev = end
print(cnt)
