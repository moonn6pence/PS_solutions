def isPrimeNum():
    primeList = [False]*2+[True]*999999
    for i in range(2, 1001):
        div = i
        if primeList[div]:
            div += i
            while(div <= 1000000):
                primeList[div] = False
                div += i
    return primeList


primeList = isPrimeNum()
while(True):
    n = int(input())
    if n == 0:
        break
    for i in range(3, n//2+1):
        if primeList[i] and primeList[n-i]:
            print(n, '=', i, '+', n-i)
            break
