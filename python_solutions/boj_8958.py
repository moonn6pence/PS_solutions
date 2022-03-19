n=int(input())
cnt=0
for i in range(n):
    omr=input()
    score=0
    cnt=0
    for j in range(len(omr)):
        if omr[j]=='O':
            cnt+=1
            score+=cnt
        else:cnt=0
    print(score)
