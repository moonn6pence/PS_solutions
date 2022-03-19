def preorder(curNode):
    if curNode == '.':
        return
    print(curNode, end='')
    preorder(Tree[curNode][0])
    preorder(Tree[curNode][1])


def inorder(curNode):
    if curNode == '.':
        return
    inorder(Tree[curNode][0])
    print(curNode, end='')
    inorder(Tree[curNode][1])


def postorder(curNode):
    if curNode == '.':
        return
    postorder(Tree[curNode][0])
    postorder(Tree[curNode][1])
    print(curNode, end='')


n = int(input())
Tree = {}

for _ in range(n):
    root, left, right = input().split()
    Tree[root] = [left, right]

preorder('A')
print()
inorder('A')
print()
postorder('A')
