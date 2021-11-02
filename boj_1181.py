import sys

n=int(input())

words=[]
for i in range(n):
    word=sys.stdin.readline().rstrip()
    words.append((len(word),word))

wordsset=set(words)
words=list(wordsset)
words.sort()

for i in range(len(words)):
    print(words[i][1])
