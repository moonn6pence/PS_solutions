from collections import deque
n = int(input())
num = [0]*(n+1)
order = deque()

order.append(n)
while order:
    cur = order.popleft()
    if cur==1:
        break
    if cur%3==0 and num[cur//3]==0:
        order.append(cur//3)
        num[cur//3]=cur
    if cur%2==0 and num[cur//2]==0:
        order.append(cur//2)
        num[cur//2]=cur
    if num[cur-1]==0:
        order.append(cur-1)
        num[cur-1]=cur
    
path=[]
cur,cnt=1,0
while cur<n:
    path.append(cur)
    cur = num[cur]
    cnt+=1
path.append(n)

print(cnt)
print(*path[::-1])