import sys
input = sys.stdin.readline

cnt = [0]*26
ans = []

n = int(input())
for i in range(n):
    word = input().strip()
    cnt[ord(word[0])-97] += 1

for i in range(26):
    if cnt[i] >= 5:
        ans.append(chr(i+97))

if not ans:
    print('PREDAJA')
else:
    print(*ans, sep='')
