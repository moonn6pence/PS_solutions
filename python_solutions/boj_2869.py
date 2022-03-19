a,b,v=map(int,input().split())

day=(v-a)//(a-b)

while True:
    if a*day-b*(day-1)>=v:break
    else:day+=1

print(day)