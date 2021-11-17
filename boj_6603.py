def comb(cur, n, r, choice):
    if r == 0:
        print(*choice, sep=' ')
        return
    if cur > n-1:
        return
    comb(cur+1, n, r-1, choice+[s[cur]])
    comb(cur+1, n, r, choice)


while True:
    case = list(map(int, input().split()))
    if not case[0]:
        break
    k = case[0]
    s = case[1:]

    comb(0, k, 6, [])
    print('')
