import sys
from collections import  Counter

def freq(nums):
    mode_nums=Counter(nums)
    ordered_mode=mode_nums.most_common()

    if len(nums)>1:
        if ordered_mode[0][1]==ordered_mode[1][1]:return ordered_mode[1][0]
        else:return ordered_mode[0][0]
    else:return ordered_mode[0][0]

n=int(sys.stdin.readline())
nums=[]
cnt=[0]*n
for i in range(n):
    nums.append(int(sys.stdin.readline()))

nums.sort()

print(int(round(sum(nums)/n,0)))
print(nums[n//2])
print(freq(nums))
print(nums[-1]-nums[0])
