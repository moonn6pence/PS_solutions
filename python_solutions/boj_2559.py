import sys
input = sys.stdin.readline

n, k = map(int, input().split())
temp = list(map(int, input().split()))

slide = 0
for i in range(k):
    slide += temp[i]

ans = slide
for i in range(k, n):
    slide += temp[i]-temp[i-k]
    ans = max(ans, slide)

print(ans)
