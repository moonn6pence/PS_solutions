import sys
n=int(input())

matrix=[0]*10001

for i in range(n):
    a=int(sys.stdin.readline())
    matrix[a]+=1

for b in range(len(matrix)):
    if matrix[b]!=0:
        for c in range(matrix[b]):
            print(b)
