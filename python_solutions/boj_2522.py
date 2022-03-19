n = int(input())
print(*[' '*(n-i)+'*'*i for i in range(1, n+1)], *
      [' '*(n-i)+'*'*i for i in range(n-1, 0, -1)], sep='\n')
