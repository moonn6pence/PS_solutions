from collections import deque


def doubledabble(dec):
    nbin = deque()
    if dec == 0:
        return [0]
    while dec != 0:
        if dec % 2:
            nbin.appendleft(dec % 2)
            dec = (dec-1)//-2
        else:
            nbin.appendleft(dec % 2)
            dec //= -2
    return nbin


dec = int(input())
print(''.join(map(str, doubledabble(dec))))
