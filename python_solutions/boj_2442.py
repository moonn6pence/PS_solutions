n = int(input())
print(*[' '*(n-i)+'*'*(i*2-1) for i in range(1, n+1)], sep='\n')
