def factor(num, fact):
    cnt = 0
    while(num >= fact):
        num //= fact
        cnt += num
    return cnt


n, m = map(int, input().split())

bin = factor(n, 2)-factor(m, 2)-factor(n-m, 2)
pen = factor(n, 5)-factor(m, 5)-factor(n-m, 5)

print(min(bin, pen))
