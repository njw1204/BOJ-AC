def BackTrack(si,sj,remain):
 global n,x
 if si>=n or sj>=n or x[si][sj]: return 0
 else:
  if remain==1: return 1
  t=[]
  for i in range(n):
   if x[i][sj]==0:
    x[i][sj]=remain
    t.append((i,sj))
   if si+i<n and sj+i<n and x[si+i][sj+i]==0:
    x[si+i][sj+i]=remain
    t.append((si+i,sj+i))
   if si+i<n and sj-i>=0 and x[si+i][sj-i]==0:
    x[si+i][sj-i]=remain
    t.append((si+i,sj-i))
 ans=0
 for i in range(n):
  ans+=BackTrack(si+1,i,remain-1)
 for i,j in t: x[i][j]=0
 return ans

n=int(input())
ans=0
for j in range(n):
 x=[[0]*n for k in range(n)]
 ans+=BackTrack(0,j,n)
print(ans)