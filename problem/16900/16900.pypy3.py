s,k=input().split()
l=len(s)
pi=[0]*l
j=0
for i in range(1,l):
 while j>0 and s[j]!=s[i]:
  j=pi[j-1]
 if s[j]==s[i]:
  j+=1
  pi[i]=j
print(l+(int(k)-1)*(l-pi[-1]))