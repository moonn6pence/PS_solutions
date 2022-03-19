ohm = {'black': 0, 'brown': 1, 'red': 2, 'orange': 3, 'yellow': 4,
       'green': 5, 'blue': 6, 'violet': 7, 'grey': 8, 'white': 9}

deci = input()
one = input()
mul = input()

print((ohm[deci]*10+ohm[one])*(10**ohm[mul]))
