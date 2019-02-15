import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

def DFS(start):
    global link,parent,visit
    visit[start]=True
    for i in link[start]:
        if not visit[i]:
            parent[i]=start
            DFS(i)

n=int(input())
link=[[] for i in range(n+1)]
parent=[0]*(n+1)
visit=[False]*(n+1)
for i in range(n-1):
    a,b=map(int,input().split())
    link[a].append(b)
    link[b].append(a)
DFS(1)
for i in range(2,n+1):
    print(parent[i])