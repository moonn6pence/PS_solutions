code = list(map(int, input().split()))
sum = 0
for n in code:
    sum += n*n
print(sum % 10)
