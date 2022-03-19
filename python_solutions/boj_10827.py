from decimal import Decimal, getcontext
getcontext().prec = 1101
a, b = map(Decimal, input().split())
print("{:f}".format(a**b))
