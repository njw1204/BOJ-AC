from collections import deque
import sys

sys.setrecursionlimit(10**8)
#sys.stdin=open("data.in","r")
#sys.stdout=open("full-connect-2.out","w")

def dfs(si, siColor):
    global n,link,visit,type
    visit[si]=True
    type[si]=siColor
    typeCnt=[0,0]
    typeCnt[type[si]]+=1

    for i in range(1,n+1):
        if link[si][i]=="1" and not visit[i]:
            x,y=dfs(i, (siColor + 1) % 2)
            typeCnt[0]+=x
            typeCnt[1]+=y

    return typeCnt

def bfs(si):
    global n,link,visit,type
    Q=deque()
    visit[si]=True
    Q.append(si)
    typeCnt=[1,0]
    while Q:
        now_i=Q.popleft()
        for i in range(1,n+1):
            if link[now_i][i]=="1" and visit[i] and type[now_i]==type[i]:
                exit(-1) # not bipartite graph
            if link[now_i][i]=="1" and not visit[i]:
                visit[i]=True
                type[i]=(type[now_i]+1)%2
                typeCnt[type[i]]+=1
                Q.append(i)
    return max(typeCnt)


n=int(input())
link=[["0" for i in range(n+2)]]
for i in range(n):
    _=input()
    for j in _:
        if j!="0" and j!="1": exit(-1)
    if len(_)!=n: exit(-1)
    link.append(["0", *list(_), "0"])
link.append(["0" for i in range(n+2)])

if not (1 <= n <= 2000): exit(-1)

# make undirected
for i in range(1,n+1):
    for j in range(1,n+1):
        if link[i][j]=="1":
            link[j][i]="1"
            pass

visit=[0]*(n+5)
type=[0]*(n+5)

ans=0
for i in range(1,n+1):
    if not visit[i]:
        ans+=max(dfs(i,0))
print(ans)