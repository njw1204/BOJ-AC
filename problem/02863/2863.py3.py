def Rotate(x):
 y=[[0]*2 for _ in range(2)]
 for i in range(2):
  for j in range(1,-1,-1):
   y[i][1-j]=x[j][i]
 return y

X=[0]*2
X[0]=[*map(int,input().split())]
X[1]=[*map(int,input().split())]

ans,max_val=0,0
for i in range(4):
 t=X[0][0]/X[1][0]+X[0][1]/X[1][1]
 if t>max_val:
  max_val=t
  ans=i
 X=Rotate(X)

print(ans)