import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def postorder(start, end):
    root = start
    if start > end:
        return
    lc = start+1
    rc = lc
    for i in range(lc, end+1):
        if inorder[i] > inorder[root]:
            rc = i
            break
    postorder(lc, rc-1)
    postorder(rc, end)
    print(inorder[root])


inorder = []
while True:
    try:
        inorder.append(int(input()))
    except:
        break
postorder(0, len(inorder)-1)
