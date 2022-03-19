from sys import stdin

n = int(stdin.readline())
num = list(map(int, stdin.readline().split()))
cnt = [0]


def mergeSort(arr):
    length = len(arr)
    if length <= 1:
        return arr
    part1 = mergeSort(arr[:length//2])
    part2 = mergeSort(arr[length//2:])
    return merge(part1, part2)


def merge(part1, part2):
    i, j = 0, 0
    len1, len2 = len(part1), len(part2)
    mergedArr = []
    while i < len1 or j < len2:
        if i == len1:
            mergedArr = mergedArr+part2[j:]
            break
        if j == len2:
            mergedArr = mergedArr+part1[i:]
            break
        if part1[i] > part2[j]:
            mergedArr.append(part2[j])
            j += 1
            cnt[0] += len1-i
        else:
            mergedArr.append(part1[i])
            i += 1
    return mergedArr


mergeSort(num)
print(cnt[0])
