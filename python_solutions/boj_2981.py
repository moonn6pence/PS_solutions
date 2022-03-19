def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


n = int(input())
num = [int(input()) for _ in range(n)]
num.sort()
diff = [num[i+1]-num[i] for i in range(n-1)]
diffGcd = diff[0]
for i in range(n-1):
    diffGcd = gcd(diffGcd, diff[i])

m = []

for i in range(2, int(diffGcd**0.5)+1):
    if diffGcd % i == 0:
        if i*i != diffGcd:
            m.append(i)
            m.append(diffGcd//i)
        else:
            m.append(i)
m.append(diffGcd)
m.sort()
print(*m)
