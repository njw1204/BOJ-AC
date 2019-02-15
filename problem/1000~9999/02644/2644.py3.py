def DFS(start,end):
  global n,graph,visit,dp
  if start==end: return 0
  elif dp[start]: return dp[start]

  dp[start]=10000
  visit[start]=True
  for i in range(1,n+1):
    if graph[start][i] and not visit[i]:
      dp[start]=min(dp[start],DFS(i,end)+1)

  visit[start]=False
  return dp[start]

n=int(input())
findA,findB=map(int,input().split())
graph=[[False]*(n+1) for i in range(n+1)]
visit=[False]*(n+1)
dp=[0]*(n+1)

for i in range(int(input())):
  a,b=map(int,input().split())
  graph[a][b]=True
  graph[b][a]=True

ans=DFS(findA,findB)
print(ans if ans<10000 else -1)