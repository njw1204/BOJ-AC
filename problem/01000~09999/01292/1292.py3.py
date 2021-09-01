A,B=map(int,input().split())
X,i,num=[0]*1000,0,1
while i<1000:
 for j in range(num):
  X[i]=num
  i+=1
  if i>=1000: break
 num+=1
print(sum(X[A-1:B]))