def Init():
 global dp
 dp=[[-1]*200 for _ in range(200)]
 
def Ans(S,T):
 global dp
 if S>T: return 999
 if S==T: return 0
 if dp[S][T]==-1:
  dp[S][T]=min(Ans(S+1,T),Ans(S*2,T+3))+1
 return dp[S][T]
 
for _ in range(int(input())):
 S,T=map(int,input().split())
 Init()
 print(Ans(S,T))