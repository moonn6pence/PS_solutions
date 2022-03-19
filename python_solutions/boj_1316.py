case=int(input())

cnt=case
alphabet=list('abcedfghijklmnopqrstuvxwyz')
for i in range(case):
    word=input()
    for s in alphabet:
        n=word.count(s)
        if n<2:pass
        elif n-1!=word.rfind(s)-word.find(s):
            cnt-=1
            break
print(cnt)
