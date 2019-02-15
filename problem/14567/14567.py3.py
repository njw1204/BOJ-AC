import sys
subject,condition=map(int,input().split())
link=[[] for i in range(subject+1)]
ans=[1]*(subject+1)
for i in range(condition):
 a,b=map(int,sys.stdin.readline().split())
 link[b].append(a)
for i in range(1,subject+1):
 for j in link[i]:
  ans[i]=max(ans[i],ans[j]+1)
for i in range(1,subject+1): print(ans[i],end=' ')