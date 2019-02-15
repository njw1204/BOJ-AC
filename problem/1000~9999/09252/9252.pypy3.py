a,b=input(),input()
lena,lenb=len(a),len(b)
dp=[[0]*(lenb+1) for i in range(lena+1)]
sol=[[0]*(lenb+1) for i in range(lena+1)]

for i in range(1,lena+1):
 for j in range(1,lenb+1):
  if a[i-1]==b[j-1]:
   dp[i][j]=dp[i-1][j-1]+1
   sol[i][j]=3
  else:
   if dp[i-1][j]>dp[i][j-1]:
    dp[i][j]=dp[i-1][j]
    sol[i][j]=1
   else:
    dp[i][j]=dp[i][j-1]
    sol[i][j]=2
x=dp[lena][lenb]
ans=[]
print(x)

i,j=lena,lenb
while x:
 if sol[i][j]==1: i-=1
 elif sol[i][j]==2: j-=1
 else:
  ans.append(a[i-1])
  i-=1
  j-=1
  x-=1
print(''.join(ans)[::-1])