M,X=0,0
for i in range(5):
 N=sum(map(int,input().split()))
 if(N>M):M,X=N,i+1
print(X,M)