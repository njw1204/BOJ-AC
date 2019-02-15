n=int(input())
t=input()
d=[0]*n
j=0
for i in range(1,n):
 while j>0 and t[i]!=t[j]: j=d[j-1]
 if t[i]==t[j]:
  d[i]=j+1
  j+=1
print(n-d[n-1])