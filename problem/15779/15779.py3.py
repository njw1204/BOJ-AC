input()
x=[*map(int,input().split())]
if x[0]<=x[1]<=x[2] or x[0]>=x[1]>=x[2]: print(2)
else: print(3)