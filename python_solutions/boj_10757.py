from itertools import zip_longest

a, b = map(list, input().split())
a = list(map(int, a))
b = list(map(int, b))
a.reverse()
b.reverse()


def stringSum(n1, n2):
    result = []
    carry = 0
    for i, j in zip_longest(n1, n2, fillvalue=0):
        sum = i+j
        if sum+carry > 9:
            result.append(sum+carry-10)
            carry = 1
        else:
            result.append(sum+carry)
            carry = 0
    if carry:
        result.append(carry)
    result.reverse()
    return ''.join(map(str, result))


print(stringSum(a, b))
