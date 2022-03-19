n = int(input())
print(*[' '*(n-i-1)+'*'*(i*2+1)
      for i in map(abs, range(n-1, -n, -1))], sep='\n')
