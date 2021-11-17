n, s = map(int, input().split())
num = list(map(int, input().split()))

cnt = [0]


def tree(cur, subSum, n, s):
    if cur > n-1:
        if subSum == s:
            cnt[0] += 1
        return
    tree(cur+1, subSum+num[cur], n, s)
    tree(cur+1, subSum, n, s)


tree(0, 0, n, s)
print(cnt[0] if s else cnt[0]-1)
