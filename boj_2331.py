A, P = map(int, input().split())
visited = []


def dfs(start, depth):
    if start in visited:
        return (start, depth)
    visited.append(start)
    n, r = dfs(calc(start, P), depth+1)
    if n == start:
        print(depth-1)
    return n, r


def calc(num, p):
    result = 0
    while num:
        result += (num % 10)**p
        num = num//10
    return result


dfs(A, 1)
