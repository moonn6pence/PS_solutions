wscore=0
for i in range(5):
    n=int(input())
    if n>40:wscore=wscore+n
    else: wscore=wscore+40
print(int(wscore/5))
