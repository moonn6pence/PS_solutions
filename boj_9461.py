n=int(input())
padovan=[1,1,1,2,2,3]+[True]*94

for i in range(6,100):
    padovan[i]=padovan[i-1]+padovan[i-5];

for i in range(n):
    print(padovan[int(input())-1])
