n = int(input())
case = []
for _ in range(n):
    tmp = list(input().split())
    score = [tmp[0]]+list(map(int, tmp[1:]))
    case.append(score)
case.sort(key=lambda x: (-x[1], x[2], -x[3], x[0]))
for i in range(n):
    print(case[i][0])
