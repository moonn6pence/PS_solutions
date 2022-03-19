import sys
input = sys.stdin.readline


class maxHeap:
    def __init__(self):
        self.data = [None]

    def insert(self, value):
        self.data.append(value)
        i = len(self.data)-1
        while i > 1:
            if self.data[i] > self.data[i//2]:
                self.data[i], self.data[i//2] = self.data[i//2], self.data[i]
                i //= 2
            else:
                break

    def removeRoot(self):
        if len(self.data) > 1:
            self.data[1], self.data[-1] = self.data[-1], self.data[1]
            ret = self.data.pop()
            self.maxHeapify(1)
        else:
            ret = 0
        return ret

    def maxHeapify(self, i):
        left = i*2
        right = i*2+1
        biggest = i
        if left < len(self.data) and self.data[biggest] < self.data[left]:
            biggest = left
        if right < len(self.data) and self.data[biggest] < self.data[right]:
            biggest = right

        if biggest != i:
            self.data[i], self.data[biggest] = self.data[biggest], self.data[i]
            self.maxHeapify(biggest)


n = int(input().rstrip())
heap = maxHeap()
garbage = []
for _ in range(n):
    x = int(input().rstrip())
    if x:
        heap.insert(x)
    else:
        garbage.append(heap.removeRoot())
print(*garbage, sep='\n')
