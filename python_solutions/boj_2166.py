import sys
input = sys.stdin.readline

n = int(input())
point = [tuple(map(int, input().split())) for _ in range(n)]
point = point[:]+point[0:1]

area1, area2 = 0, 0
for i in range(n):
    area1 += point[i][0]*point[i+1][1]
    area2 += point[i][1]*point[i+1][0]

print(round(abs(area1-area2)/2, 1))
