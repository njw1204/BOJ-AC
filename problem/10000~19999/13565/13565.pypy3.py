from collections import deque

n,m=map(int,input().split())
field=[]
field.append("1"*(m+2))
for i in range(n):
    field.append("1"+input()+"1")
field.append("1"*(m+2))
visit=[[False]*1005 for i in range(1005)]
Q=deque()

for i in range(1,m+1):
    if field[1][i]=="0":
        visit[1][i]=True
        Q.append([1,i])

while Q:
    i,j=Q.popleft()
    dx=[[0,1],[0,-1],[1,0],[-1,0]]
    for ddx,ddy in dx:
        if field[i+ddx][j+ddy]=="0" and visit[i+ddx][j+ddy]==False:
            visit[i+ddx][j+ddy]=True
            Q.append([i+ddx,j+ddy])
            if i+ddx==n:
                print("YES")
                exit(0)
print("NO")