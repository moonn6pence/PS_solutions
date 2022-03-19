new=['c=','c-','dz=','d-','lj','nj','s=','z=']
word=input()
cnt=0
for w in new:
    cnt+=word.count(w)
    word=word.replace(w,' ')
word=word.replace(' ','')
print(len(word)+cnt)
