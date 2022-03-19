dwarf = [int(input()) for _ in range(9)]
dwarf.sort()
total = sum(dwarf)

diff = total-100

flag = False
for i in range(9):
    for j in range(i+1, 9):
        if dwarf[i]+dwarf[j] == diff:
            fake = [i, j]
            flag = True
            break
    if flag:
        break

for i in range(9):
    if i not in fake:
        print(dwarf[i])
