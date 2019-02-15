input()
x=[*map(int,input().split())]
x.extend(map(int,input().split()))
x.sort()
for i in x: print(i,end=' ')