import sys
sys.setrecursionlimit(10**6)

def dfs(s):
 global adj,res,p,n
 visit[s]=1
 while p<n:
  if res[p] in adj[s]:
   c=res[p]
   p+=1
   dfs(c)
  else: return

n=int(input())
visit=[0]*(n+1)
adj=[set() for i in range(n+1)]
for i in range(n-1):
 x,y=map(int,input().split())
 adj[x].add(y)
 adj[y].add(x)
res=[*map(int,input().split())]
p=1
dfs(1)
print(+(sum(visit)==n))