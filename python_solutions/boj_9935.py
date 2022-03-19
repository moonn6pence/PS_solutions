trgt = input()
bomb = list(input())
stack = []
size = len(bomb)
top = -1
for i in range(len(trgt)):
    stack.append(trgt[i])
    top += 1
    j, tmp = top, size-1
    isBomb = False
    while j >= 0 and stack[j] == bomb[tmp]:
        if tmp == 0:
            isBomb = True
            break
        tmp -= 1
        j -= 1
    if isBomb:
        for _ in range(size):
            stack.pop()
            top -= 1
print(*stack if stack else 'FRULA', sep='')
