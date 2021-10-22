import sys
T = int(input())
for _ in range(T):
    func = list(input())
    reverseFlag = False
    errorFlag = False
    n = int(input())
    seq = list(map(int, input().strip('[]').split(','))
               ) if n else list(input().strip('[]'))
    for f in func:
        if f == 'R':
            reverseFlag = False if reverseFlag else True
        elif f == 'D' and n == 0:
            print('error')
            errorFlag = True
            break
        else:
            if reverseFlag:
                n -= 1
                seq.pop()
            else:
                n -= 1
                seq.pop(0)
    if errorFlag:
        continue
    if reverseFlag:
        seq.reverse()
    result = '['+','.join(map(str, seq))+']'
    print(result)
