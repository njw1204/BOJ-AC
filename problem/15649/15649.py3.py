def BackTrack(now,fin):
 global N,visit,result
 for i in range(1,N+1):
  if visit[i]: continue
  visit[i]=1
  result.append(i)
  if now<fin: BackTrack(now+1,fin)
  else: print(' '.join(map(str,result)))
  visit[i]=0
  result.pop()

result=[]
N,M=map(int,input().split())
visit=[0]*(N+1)
BackTrack(1,M)