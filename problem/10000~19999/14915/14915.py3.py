m,n=map(int,input().split())
x=[]
if m==0:
 print(0)
 exit()
while m:
 x.append(str(m%n))
 m//=n
for i in range(len(x)):
 if x[i]=='10': x[i]='A'
 elif x[i]=='11': x[i]='B'
 elif x[i]=='12': x[i]='C'
 elif x[i]=='13': x[i]='D'
 elif x[i]=='14': x[i]='E'
 elif x[i]=='15': x[i]='F'
print(''.join(reversed(x)))