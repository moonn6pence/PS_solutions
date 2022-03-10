import sys
input = sys.stdin.readline

word = list(input().strip())
char = [0]*26

for a in word:
    char[ord(a)-65] += 1

cnt = 0
flag = False

for c in char:
    if c % 2 != 0:
        cnt += 1
        if cnt > 1:
            flag = True
            print('I\'m Sorry Hansoo')
            break


ans = ['_']*len(word)
pos = 0

for i in range(26):
    if char[i] > 0:
        for j in range(char[i]//2):
            ans[pos+j] = chr(i+65)
            ans[len(word)-1-pos-j] = chr(i+65)
        pos += char[i]//2
        if char[i] % 2 != 0:
            ans[len(word)//2] = chr(i+65)

if not flag:
    print(*ans, sep='')
