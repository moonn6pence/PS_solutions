word=input()
cnt_list=[]
for i in range(26):
    cnt=0
    for s in word:
        if chr(i+65)==s or chr(i+97)==s: cnt+=1
    cnt_list.append(cnt)
max_case=max(cnt_list)
n=cnt_list.index(max_case)
cnt_list.remove(max_case)
if max_case in cnt_list:print('?')
else:print(chr(n+65))
