import sys
input = sys.stdin.readline


class minHeap:
    def __init__(self):
        self.data = [None]

    def insert(self, value):
        self.data.append(value)
        i = len(self.data)-1
        while i > 1:
            if self.data[i] < self.data[i//2]:
                self.data[i], self.data[i//2] = self.data[i//2], self.data[i]
                i //= 2
            else:
                break

    def removeRoot(self):
        if len(self.data) > 1:
            self.data[1], self.data[-1] = self.data[-1], self.data[1]
            ret = self.data.pop()
            self.minHeapify(1)
        else:
            ret = 0
        return ret

    def minHeapify(self, i):
        left = i*2
        right = i*2+1
        smallest = i
        if left < len(self.data) and self.data[smallest] > self.data[left]:
            smallest = left
        if right < len(self.data) and self.data[smallest] > self.data[right]:
            smallest = right

        if smallest != i:
            self.data[i], self.data[smallest] = self.data[smallest], self.data[i]
            self.minHeapify(smallest)


n = int(input().rstrip())
heap = minHeap()
garbage = []
for _ in range(n):
    x = int(input().rstrip())
    if x:
        heap.insert(x)
    else:
        garbage.append(heap.removeRoot())
print(*garbage, sep='\n')
