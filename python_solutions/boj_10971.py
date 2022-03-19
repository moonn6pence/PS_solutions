n = int(input())
cost = [list(map(int, input().split())) for _ in range(n)]
visited = [False for _ in range(n)]
minCost = [1000000000]


def backtrack(start, curNode, subSum, depth):
    if depth == n-1:
        subSum += cost[curNode][start]
        if subSum < minCost[0] and cost[curNode][start]:
            minCost[0] = subSum
        return

    for node in range(n):
        if not visited[node] and cost[curNode][node] and minCost[0] >= subSum+cost[curNode][node]:
            visited[node] = True
            backtrack(start, node, subSum + cost[curNode][node], depth+1)
            visited[node] = False


for i in range(n):
    visited[i] = True
    backtrack(i, i, 0, 0)
    visited[i] = False

print(minCost[0])
