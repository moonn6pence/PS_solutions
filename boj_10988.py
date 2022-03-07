import sys
input = sys.stdin.readline

word = input().strip()
n = len(word)
stack = []
flag = False

for i in range(n//2):
    stack.append(word[i])

s = n//2 if n % 2 == 0 else n//2+1

for i in range(s, n):
    if stack.pop() != word[i]:
        flag = True
        break

if flag:
    print(0)
else:
    print(1)
