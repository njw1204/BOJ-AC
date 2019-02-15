for _ in range(int(input())):
 P,M=map(int,input().split())
 L=[0]*M
 for __ in range(P): L[int(input())-1]+=1
 ans=0
 for i in L:
  if i>1: ans+=i-1
 print(ans)