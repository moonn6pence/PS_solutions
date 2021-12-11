exp = input()
op = []

for c in exp:
    if 'A' <= c <= 'Z':
        print(c, end='')
    elif c == '(':
        op.append('(')
    elif c == ')':
        while op[-1] != '(':
            print(op.pop(), end='')
        op.pop()
    else:
        if c == '+' or c == '-':
            while op and op[-1] != '(':
                print(op.pop(), end='')
            op.append(c)
        else:
            while op and op[-1] != '(':
                if op[-1] == '+' or op[-1] == '-':
                    break
                print(op.pop(), end='')
            op.append(c)


while op:
    print(op.pop(), end='')
