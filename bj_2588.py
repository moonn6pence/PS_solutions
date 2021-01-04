a=int(input())
b=int(input())
print(*[a*int(x) for x in list(reversed(str(b)))],a*b,sep='\n')