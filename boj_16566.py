import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
deck = list(map(int, input().split()))
red = list(map(int, input().split()))
parent = [i for i in range(m+1)]
deck.sort()


def parametricSearch(x):
    low, high = 0, m-1
    while low < high:
        mid = (low+high)//2
        if deck[mid] > x:
            high = mid
        else:
            low = mid+1
    return low


def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return
    parent[a] = b


for x in red:
    idx = find(parametricSearch(x))
    print(deck[idx])
    union(idx, idx+1)
