x=[]
for i in range(99):
 for j in bin(i)[2:]: x.append(j)
n,k=map(int,input().split())
for i in range(5):
 print(x[k-1+n*i],end=' ')