n=list(input())
total_time=[]
for w in n:
    if w in ['A', 'B', 'C']:
        total_time.append(3)
    elif w in ['D','E', 'F']:
        total_time.append(4)
    elif w in ['G', 'H', 'I']:
        total_time.append(5)
    elif w in ['J', 'K', 'L']:
        total_time.append(6)
    elif w in ['M', 'N', 'O']:
        total_time.append(7)
    elif w in ['P', 'Q', 'R', 'S']:
        total_time.append(8)
    elif w in ['T', 'U', 'V']:
        total_time.append(9)
    elif w in ['W', 'X', 'Y', 'Z']:
        total_time.append(10)
    else:
        total_time.append(11)
        
print(sum(total_time))
