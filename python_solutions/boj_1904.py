n=int(input())

tile=[0,1,2]+[0]*999999

for i in range(3,n+1):
    tile[i]=(tile[i-1]+tile[i-2])%15746

print(tile[n])
