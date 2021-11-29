import sys

n, r, c = map(int, input().split())
size = 2**n
order = [0]
ans = []


def visit(size, r, c, curr, curc):
    if size == 1:
        if curr == r and curc == c:
            print(order[0])
            sys.exit(0)
        order[0] += 1
        return

    size //= 2
    if r < curr+size and c < curc+size:
        visit(size, r, c, curr, curc)
    elif r < curr+size and c >= curc+size:
        order[0] += size**2
        visit(size, r, c, curr, curc+size)
    elif r >= curr+size and c < curc+size:
        order[0] += size**2*2
        visit(size, r, c, curr+size, curc)
    else:
        order[0] += size**2*3
        visit(size, r, c, curr+size, curc+size)


visit(size, r, c, 0, 0)
