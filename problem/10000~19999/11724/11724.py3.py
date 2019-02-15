import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

def DFS(start):
    global visit,link
    visit[start]=True
    for i in link[start]:
        if not visit[i]:
            DFS(i)


n,m=map(int,input().split())
visit=[False]*(n+5)
link=[[] for i in range(n+5)]
for i in range(m):
    a,b=map(int,input().split())
    link[a].append(b)
    link[b].append(a)
ans=0
for i in range(1,n+1):
    if not visit[i]:
        ans+=1
        DFS(i)
print(ans)