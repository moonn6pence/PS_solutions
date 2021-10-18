month = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
week = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
m, d = map(int, input().split())
days = sum(month[:m])
print(week[(days + d - 1) % 7])
