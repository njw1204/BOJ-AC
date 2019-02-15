def DFS(start):
 global comCnt,edge,visit,ans
 if visit[start]: return
 else:
  visit[start]=True
  ans+=1
 for i in range(1,comCnt+1):
  if edge[start][i]: DFS(i)

comCnt,pairCnt=int(input()),int(input())
edge=[[False]*(comCnt+1) for i in range(comCnt+1)]
for i in range(pairCnt):
 a,b=map(int,input().split())
 edge[a][b]=True
 edge[b][a]=True
visit=[False]*(comCnt+1)
ans=0
DFS(1)
print(ans-1)