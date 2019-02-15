from collections import deque

n,m=map(int,input().split())
field=[["X"]*(m+5) for i in range(n+5)]
for i in range(1,n+1):
    field[i]=["X"]
    field[i].extend(list(input()))
    field[i].append("X")
visit=[[0]*(m+5) for i in range(n+5)]
a=0

for i in range(1,n+1):
    for j in range(1,m+1):
        if visit[i][j]: continue
        
        visit[i][j]=1
        a+=1
        q=deque()
        q.append((i,j))

        while q:
            si,sj=q.popleft()

            if field[si][sj]=="L" and not visit[si][sj-1]:
                visit[si][sj-1]=1
                q.append((si,sj-1))
            elif field[si][sj]=="R" and not visit[si][sj+1]:
                visit[si][sj+1]=1
                q.append((si,sj+1))
            elif field[si][sj]=="U" and not visit[si-1][sj]:
                visit[si-1][sj]=1
                q.append((si-1,sj))
            elif field[si][sj]=="D" and not visit[si+1][sj]:
                visit[si+1][sj]=1
                q.append((si+1,sj))

            if field[si][sj-1]=="R" and not visit[si][sj-1]:
                visit[si][sj-1]=1
                q.append((si,sj-1))
            if field[si][sj+1]=="L" and not visit[si][sj+1]:
                visit[si][sj+1]=1
                q.append((si,sj+1))
            if field[si-1][sj]=="D" and not visit[si-1][sj]:
                visit[si-1][sj]=1
                q.append((si-1,sj))
            if field[si+1][sj]=="U" and not visit[si+1][sj]:
                visit[si+1][sj]=1
                q.append((si+1,sj))

print(a)