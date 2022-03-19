n = int(input())
string = input()
hash = 0
M = 1234567891
for i in range(n):
    ex = i
    tmp = 1
    r = 31
    while ex:
        if ex % 2 == 1:
            tmp = (tmp*r) % M
        r = (r*r) % M
        ex //= 2
    hash += ((ord(string[i])-96)*tmp) % M
    hash %= M
print(hash)
