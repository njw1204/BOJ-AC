N,M=int(input()),int(input())
L=[0]*(M//2+1)
X=[*map(int,input().split())]
for i in X:
 if i>M/2 and i<=M: L[M-i]+=1
 elif i<M/2: L[i]+=1
ans=0
for i in L:
 if i==2: ans+=1
print(ans)