from collections import deque

n = int(input())
deck = deque()
for i in range(1, n+1):
    deck.append(i)

for _ in range(n-1):
    deck.popleft()
    tmp = deck.popleft()
    deck.append(tmp)

print(deck[0])
