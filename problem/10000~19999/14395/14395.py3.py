def dfs(s,t,r):
 if s==t:
  return r
 if s>t:
  return -1
 a1=dfs(s*s,t,r+"*") if s>1 else -1
 a2=dfs(s+s,t,r+"+")
 if a1==-1: return a2
 if a2==-1: return a1
 if len(a1)<=len(a2): return a1
 else: return a2

s,t=map(int,input().split())
if s==t:
 print(0)
 exit()
a1=dfs(s,t,"")
a2=dfs(1,t,"/")
if a1==-1: ans=a2
elif a2==-1: ans=a1
elif len(a1)<=len(a2): ans=a1
else: ans=a2
print(ans)