n,m=map(int,input().split())
x=[*map(int,input().split())]
money,maxCap=0,0
for i in range(len(x)):
    money+=x[i]
    if i>=m: money-=x[i-m]
    maxCap=max(maxCap,money)
print(maxCap)