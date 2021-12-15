n = int(input())
f = int(input())

x = n-n % 100

while x % f != 0:
    x += 1

x = str(x)
print(x[-2], x[-1], sep='')
