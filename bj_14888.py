n=int(input())
a=list(map(int,input().split()))
op_num=list(map(int,input().split()))
op=[1]*op_num[0]+[2]*op_num[1]+[3]*op_num[2]+[4]*op_num[3]
visited=[False]*(n-1)
temp_min,temp_max=10**9,-10**9
result=[a[0]]

def cal(i,depth):
    if op[i]==1: result.append(result[-1]+a[depth+1])
    elif op[i]==2:result.append(result[-1]-a[depth+1])
    elif op[i]==3:result.append(result[-1]*a[depth+1])
    elif op[i]==4 and result[-1]<0 : result.append((result[-1]*(-1)//a[depth+1])*(-1))
    else : result.append(result[-1]//a[depth+1])
    return

def op_ins(depth):
    global temp_min,temp_max
    if depth==n-1:
        temp_min=min(temp_min,result[-1])
        temp_max=max(temp_max,result[-1])
        return
    
    for i in range(n-1):
        if not visited[i]:
            visited[i]=True
            cal(i,depth)
            op_ins(depth+1)
            result.pop()
            visited[i]=False

op_ins(0)
print(temp_max)
print(temp_min)
