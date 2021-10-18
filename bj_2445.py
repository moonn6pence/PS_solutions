n = int(input())
print(*['*'*i+' '*((n-i)*2)+'*'*i for i in range(1, n+1)],
      *['*'*i+' '*((n-i)*2)+'*'*i for i in range(n-1, 0, -1)], sep='\n')
