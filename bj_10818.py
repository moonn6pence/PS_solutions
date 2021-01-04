n=int(input())
seq=list(map(int,input().split()))
seq.sort()
print(seq[0],seq[n-1])
