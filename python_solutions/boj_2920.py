code = list(map(int, input().split()))
asc = [x+1 for x in range(8)]
dsc = [x for x in range(8, 0, -1)]
if code == asc:
    print('ascending')
elif code == dsc:
    print('descending')
else:
    print('mixed')
