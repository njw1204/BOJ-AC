x=[3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]
a,b=input(),input()
c=[]
for i in range(len(a)):
 c.append(x[ord(a[i])-ord('A')])
 c.append(x[ord(b[i])-ord('A')])
for i in range(len(c)-1,1,-1):
 for j in range(i):
  c[j]=(c[j]+c[j+1])%10
print(c[0],c[1],sep='')