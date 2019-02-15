input()
x=[*map(int,input().split())]
s=[]
for n,i in enumerate(x):
 while s:
  if s[-1][1]<i: s.pop()
  else: break
 if not s: print(0,end=' ')
 else: print(s[-1][0],end=' ')
 s.append([n+1,i])