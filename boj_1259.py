while True:
    num = int(input())
    if not num:
        break
    num = list(map(int, str(num)))
    flag = True
    for i in range(len(num)//2+1):
        if num[i] != num[-i-1]:
            flag = False
            break
    print('yes' if flag else 'no')
