n = int(input())
seq = [int(input()) for _ in range(n)]
seq.sort()
sum = 0


def countPos(num):
    pos = 0
    neg = 0
    isOne = 0
    for n in num:
        if n > 1:
            pos += 1
        elif n <= 0:
            neg += 1
        elif n == 1:
            isOne += 1
    return pos, neg, isOne


pos, neg, isOne = countPos(seq)

if pos > 0:
    for i in range(n-1, n-pos, -2):
        sum += seq[i]*seq[i-1]
    if pos % 2 == 1:
        sum += seq[n-pos]

if isOne:
    sum += isOne

if neg > 0:
    for i in range(0, neg-1, 2):
        sum += seq[i]*seq[i+1]
    if neg % 2 == 1:
        sum += seq[neg-1]

print(sum)
