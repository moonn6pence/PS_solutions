num = list(map(int, input()))
num.sort(reverse=True)

i = 0
sum = 0
while i < len(num) and num[i]:
    sum += num[i]
    i += 1

if sum % 3 == 0 and num[-1] == 0:
    print(*num, sep='')
else:
    print(-1)
