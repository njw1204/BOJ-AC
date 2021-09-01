n=int(input())
arr=[]
for i in range(n):
    x,y=map(int,input().split())
    arr.append([x,y])
dist=10**18
ax,ay=arr[0]
for i in range(n):
    tDist=-(10**18)
    for j in range(n):
        if i==j: continue
        tDist=max(tDist,(arr[i][0]-arr[j][0])**2+(arr[i][1]-arr[j][1])**2)
    if tDist<dist:
        dist=tDist
        ax,ay=arr[i]
print(ax,ay)