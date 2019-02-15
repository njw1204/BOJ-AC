T=input()
ans=level=i=0
while i<len(T):
 if i<len(T)-1 and T[i]=='(' and T[i+1]==')':
  ans+=level
  i+=2
 elif T[i]=='(':
  level+=1
  i+=1
 elif T[i]==')':
  ans+=1
  level-=1
  i+=1
print(ans)