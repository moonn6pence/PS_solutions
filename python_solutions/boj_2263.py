import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


def preorder(inS, inE, postS, postE):
    if inS > inE or postS > postE:
        return
    root = postorder[postE]
    print(root, end=' ')
    preorder(inS, lookup[root]-1, postS, postS+lookup[root]-inS-1)
    preorder(lookup[root]+1, inE, postS+lookup[root]-inS, postE-1)


n = int(input())
lookup = [0]*100001
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
for i in range(n):
    lookup[inorder[i]] = i
preorder(0, n-1, 0, n-1)
