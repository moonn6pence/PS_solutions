n=int(input())
scoresum=0
score=list(map(int,input().split()))
for i in score:
    scoresum=scoresum+i/max(score)*100
print(scoresum/n)
