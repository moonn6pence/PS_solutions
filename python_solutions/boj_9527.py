a, b = map(int, input().split())


def count1(num):
    cnt = 0
    k = 1
    t = 2
    while k <= (num+1):
        q = (num+1)//t
        r = (num+1) % t
        rr = r-k if r > k else 0
        cnt += q*k+rr
        k *= 2
        t *= 2
    return cnt


print(count1(b)-count1(a-1))
