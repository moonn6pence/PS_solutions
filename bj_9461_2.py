T = int(input())
case = [int(input()) for _ in range(T)]
for n in case:
    pn = [1, 1, 1, 2, 2]+[0]*(n-3)
    for i in range(5, n):
        pn[i] = pn[i-5]+pn[i-1]
    print(pn[n-1])
