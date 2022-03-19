class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.child = {}


class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        curNode = self.head

        for c in string:
            if c not in curNode.child:
                curNode.child[c] = Node(c)
            curNode = curNode.child[c]
        curNode.data = string

    def subSearch(self, string):
        curNode = self.head
        for c in string:
            if c in curNode.child:
                curNode = curNode.child[c]
                if curNode.data != None and curNode.data != string:
                    return True
            else:
                return False
        return False


for _ in range(int(input())):
    n = int(input())
    nums = [list(map(int, input())) for _ in range(n)]
    tmpTrie = Trie()
    flag = True
    for num in nums:
        tmpTrie.insert(num)

    for num in nums:
        if tmpTrie.subSearch(num):
            flag = False
            break

    print('YES' if flag else 'NO')
