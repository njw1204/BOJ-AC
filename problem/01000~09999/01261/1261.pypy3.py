from collections import deque

m,n=map(int,input().split())
field=["1"*(m+2)]
for i in range(n):
    field.append("1"+input()+"1")
field.append("1"*(m+2))

visit=[[0]*(m+5) for i in range(n+5)]
dq=deque()
visit[1][1]=1
dq.append([1,1])

while dq:
    si,sj=dq.popleft()
    dx=[[0,1],[0,-1],[1,0],[-1,0]]
    for ddx in dx:
        i,j=si+ddx[0],sj+ddx[1]
        if not visit[i][j] and 1 <= i <= n and 1 <= j <= m:
            if field[i][j]=="0":
                dq.appendleft([i,j])
                visit[i][j]=visit[si][sj]
            else:
                dq.append([i,j])
                visit[i][j]=visit[si][sj]+1

print(visit[n][m]-1)