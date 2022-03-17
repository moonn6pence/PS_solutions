import re
import sys
input = sys.stdin.readline

n = int(input())
num = []
for _ in range(n):
    line = input()
    num = num+list(map(int, re.findall(r'\d+', line)))

num.sort()
print(*num, sep='\n')
