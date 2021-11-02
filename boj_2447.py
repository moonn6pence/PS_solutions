def fractal(n):
    matrix=[]
    
    for i in range(len(n)*3):
        if i//len(n)==1:
            matrix.append(n[i%len(n)]+" "*len(n)+n[i%len(n)])
        else:
            matrix.append(n[i%len(n)]*3)
    return(matrix)
            
    
base=['***','* *','***']

n=int(input())

k=0

while n!=3:
    n=n//3
    k+=1

for i in range(k):
    base=fractal(base)

for _ in base:
    print(_)
