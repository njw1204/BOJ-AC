dp=[[False]*1001 for i in range(4)]
x=1
while x*(x+1)//2<=1000:
 dp[1][x*(x+1)//2]=True
 x+=1
for n in range(1,3):
 for i in range(1,1001):
  if dp[n][i]:
   x=1
   while x*(x+1)//2+i<=1000:
    dp[n+1][x*(x+1)//2+i]=True
    x+=1

for _ in range(int(input())): print(+dp[3][int(input())])