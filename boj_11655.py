import sys

word = sys.stdin.readline().rstrip()
ans = []
for a in word:
    n = ord(a)
    if 65 <= n <= 90:
        n = (n+13-65) % 26
        ans.append(chr(n+65))
    elif 97 <= n <= 122:
        n = (n+13-97) % 26
        ans.append(chr(n+97))
    else:
        ans.append(a)

print(*ans, sep='')
