for T in range(1,int(input())+1):
 t,c=input().split()
 t=list(t)
 c=int(c)
 ans=0
 for i in range(len(t)-c+1):
  if t[i]=='-':
   ans+=1
   for j in range(i,i+c): t[j]='+' if t[j]=='-' else '-'
 if not '-' in t: print('Case #%d:'%T,ans)
 else: print('Case #%d: IMPOSSIBLE'%T)