x=input()
n,t=len(x),''
for i in range(n-2):
 for j in range(i+1,n-1):
  o=x[i::-1]+x[j:i:-1]+x[:j:-1]
  t=min(t,o)if t else o
print(t)