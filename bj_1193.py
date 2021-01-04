x=int(input())

n=1

while True:
    if x>=(n**2-n)/2+1 and x<=(n**2+n)/2:
        line=n-x+(n**2-n)/2+1
        break
    else:n+=1
depth=n+1-line

if n%2:print("%d/%d"%(line,depth))
else:print("%d/%d"%(depth,line))
