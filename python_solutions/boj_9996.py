import sys
input = sys.stdin.readline

n = int(input())
prefix, suffix = input().rstrip().split('*')

for _ in range(n):
    flag = True
    word = input().strip()
    length = len(word)

    if length < len(prefix)+len(suffix):
        print('NE')
        continue

    for i in range(len(prefix)):
        if prefix[i] != word[i]:
            flag = False
            break

    if not flag:
        print('NE')
        continue

    for j in range(length-len(suffix), length):
        if suffix[j-length+len(suffix)] != word[j]:
            flag = False
            break

    if not flag:
        print('NE')
        continue

    print('DA')
