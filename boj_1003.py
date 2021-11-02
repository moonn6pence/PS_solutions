n=int(input())
fibo=[(1,0),(0,1)]

for i in range(2,41):
    fibo.append((fibo[i-1][0]+fibo[i-2][0],fibo[i-1][1]+fibo[i-2][1]))
    
for i in range(n):
    m=int(input())
    print(fibo[m][0],fibo[m][1])
