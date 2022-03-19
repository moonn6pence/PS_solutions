def seq(depth, n, m, cur):
    if depth == m:
        print(' '.join(map(str, result)))
        return
    for i in range(cur, n):
        result.append(num[i])
        seq(depth+1, n, m, i)
        result.pop()


n, m = map(int, input().split())
num = sorted(list(set(map(int, input().split()))))
n = len(num)
result = []
seq(0, n, m, 0)
