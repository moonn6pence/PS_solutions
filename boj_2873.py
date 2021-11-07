r, c = map(int, input().split())
land = [list(map(int, input().split())) for _ in range(r)]
route = []
if r % 2 == 1:
    for i in range(r):
        if i % 2 == 0:
            route.append('R'*(c-1))
        else:
            route.append('L'*(c-1))
        if i < r-1:
            route.append('D')
elif c % 2 == 1:
    for i in range(c):
        if i % 2 == 0:
            route.append('D'*(r-1))
        else:
            route.append('U'*(r-1))
        if i < c-1:
            route.append('R')
else:
    minJoy = 1000
    for i in range(r):
        for j in range(c):
            if (i+j) % 2 == 1 and minJoy > land[i][j]:
                minJoy = land[i][j]
                passPoint = (i, j)
    i, j = 0, 0
    while not(i == r-1 and j == c-1):
        if passPoint[0] % 2 == 0 and i == passPoint[0]:
            if j != c-1 and j != passPoint[1]-1:
                route.append('DRUR')
                j += 2
            elif passPoint[1] < c-1 and j == passPoint[1]-1:
                route.append('DRRUR')
                j += 3
            elif passPoint[1] == c-1 and j == passPoint[1]-1:
                route.append('DR')
                i += 1
                j += 1
                if i != r-1:
                    route.append('D')
                    i += 1
            else:
                route.append('DD')
                i += 2
        elif passPoint[0] % 2 == 1 and i+1 == passPoint[0]:
            if j != c-1 and j != passPoint[1]:
                route.append('DRUR')
                j += 2
            elif passPoint[1] < c-1 and j == passPoint[1]:
                route.append('R')
                j += 1
            else:
                route.append('D')
                i += 1
                if i != r-1:
                    route.append('D')
                    i += 1
        else:
            if j == c-1:
                route.append('L'*(c-1)+'D')
                i += 1
                j = 0
            elif j == 0:
                route.append('R'*(c-1))
                j = c-1
                if i != r-1:
                    route.append('D')
                    i += 1
print(''.join(map(str, route)))
