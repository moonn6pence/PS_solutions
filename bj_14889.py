from itertools import combinations

n=int(input())
ability=[list(map(int,input().split())) for _ in range(n)]
members=[i for i in range(n)]
teams=[]

for team in list(combinations(members,n//2)):
    teams.append(team)

def ability_sum(nums):
    result=0
    for i in nums:
        for j in nums:result+=ability[i][j]
    return result

def select(depth):
    min_temp=10000
    for i in range(len(teams)//2):
        team = teams[i]
        team1=ability_sum(team)
        team = teams[-i-1]
        team2=ability_sum(team)
        min_temp=min(min_temp,abs(team1-team2))

    return min_temp

print(select(0))
