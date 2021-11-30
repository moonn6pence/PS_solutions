import sys
input = sys.stdin.readline

n, m = map(int, input().split())
guideDict = dict()
guideList = [0]

for i in range(1, n+1):
    pokemon = input().rstrip()
    guideList.append(pokemon)
    guideDict[pokemon] = i

for j in range(m):
    query = input().rstrip()
    if query.isalpha():
        print(guideDict[query])
    else:
        print(guideList[int(query)])
