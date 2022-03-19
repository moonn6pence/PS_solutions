n, m = map(int, input().split())
heardless = sorted(list(input() for _ in range(n)))
seenless = sorted(list(input() for _ in range(m)))
ans = []


def binSearch(low, high, target):
    start = low
    while low <= high:
        mid = (low+high)//2
        if seenless[mid] == target:
            return (True, mid)
        elif seenless[mid] > target:
            high = mid-1
        else:
            low = mid+1
    return (False, start)


start = 0
for man in heardless:
    flag, start = binSearch(start, m-1, man)
    if flag:
        ans.append(man)

print(len(ans), *ans, sep='\n')
