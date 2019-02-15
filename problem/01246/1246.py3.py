import sys
n,m=map(int,input().split())
x,max_profit,ans_a,ans_b,cnt=[0]*m,0,0,0,1
for i in range(m): x[i]=int(sys.stdin.readline())
x.sort()
for i in range(m-1,-1,-1):
 if x[i]*cnt>max_profit:
  ans_a,ans_b=x[i],x[i]*cnt
  max_profit=x[i]*cnt
 if cnt<n: cnt+=1
print(ans_a,ans_b)