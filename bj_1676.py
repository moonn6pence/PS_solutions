n = int(input())

zeroCnt = 0
facto = [1]*(n+1)
for i in range(1, n+1):
    facto[i] = facto[i-1]*i

target = facto[n]
while(True):
    if target % 10 == 0:
        zeroCnt += 1
        target //= 10
    else:
        break
print(zeroCnt)
