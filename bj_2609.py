def GCD(a, b):
    if a % b == 0:
        return b
    else:
        return GCD(b, a % b)


a, b = map(int, input().split())
if a >= b:
    gcd = GCD(a, b)
else:
    gcd = GCD(b, a)

print(gcd)
print(a*b//gcd)
