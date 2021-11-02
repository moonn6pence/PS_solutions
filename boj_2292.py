num=int(input())

n=2
route=1

while True:
    if num==1:break
    elif num>=(n**2)*3-n*9+8 and num<=(n**2)*3-n*3+1:
        route=n
        break
    else:n+=1
print(route)
