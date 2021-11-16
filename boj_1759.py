length, num = map(int, input().split())
charInput = sorted(list(input().split()))
jaum = ['a', 'e', 'i', 'o', 'u']
ans = []


def backtrack(cur, code, length):
    if len(code) >= length:
        j = 0
        for c in code:
            if c in jaum:
                j += 1
        if j > 0 and len(code)-j > 1:
            ans.append(code)
        return

    for i in range(cur+1, len(charInput)+len(code)-length+1):
        backtrack(i, code+charInput[i], length)


for i in range(num-length+1):
    backtrack(i, charInput[i], length)

print(*ans, sep='\n')
