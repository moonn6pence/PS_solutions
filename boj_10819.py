from itertools import permutations

n = int(input())
a = list(map(int, input().split()))

permA = permutations(a, n)


def getGapSum(nums):
    sum = 0
    for i in range(n-1):
        sum += abs(nums[i]-nums[i+1])
    return sum


maxGapSum = 0
for nums in permA:
    maxGapSum = max(maxGapSum, getGapSum(nums))

print(maxGapSum)
