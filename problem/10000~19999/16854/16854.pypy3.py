s=input()
dp=[[False]*5050 for _ in range(5050)]
for i in range(1,len(s)):
 for j in range(len(s)-i):
  dp[j][j+i]=s[j]!=s[j+i]
  if i>1: dp[j][j+i]&=dp[j+1][j+i-1]
ans=0
for i in range(len(s)):
 level=0
 for j in range(len(s)-i):
  if s[i+j]=='(': level+=1
  else: level-=1
  if level<0: break
  elif level==0 and dp[i][i+j]: ans+=1
print(ans)