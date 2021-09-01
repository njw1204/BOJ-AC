n,m,T=int(input()),int(input()),input()
ans,i=0,0
while i<len(T)-2:
 if T[i]=='I' and T[i+1]=='O':
  i+=3
  if T[i-1]=='I':
   tempLen=1
   while i<len(T)-1:
    if T[i]=='O':
     i+=2
     if T[i-1]=='I': tempLen+=1
     else: break
    else: break
   if tempLen>=n: ans+=tempLen-n+1
 else: i+=1
print(ans)