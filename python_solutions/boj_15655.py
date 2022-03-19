def seq(depth, n, m, cur):
    if depth == m:
        print(' '.join(map(str, result)))

    for i in range(cur, n):
        result.append(num[i])
        seq(depth+1, n, m, i+1)
        result.pop()


n, m = map(int, input().split())
num = sorted(list(map(int, input().split())))
result = []
seq(0, n, m, 0)
