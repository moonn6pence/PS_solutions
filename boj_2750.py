n=int(input())
nums=[]
for i in range(n):
    nums.append(int(input()))

for i in range(n-1):
    temp=0
    temp=nums[i]
    temp_index=nums.index(min(nums[i:]))
    nums[i]=min(nums[i:])
    nums[temp_index]=temp

for i in range(n):
    print(nums[i])
