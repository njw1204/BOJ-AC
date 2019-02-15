pprev,prev,now=0,0,1
n=int(input())
if n<2: print(n)
else:
 for i in range(2,n+1):
  pprev=prev
  prev=now
  now=(pprev+prev)%1000000007
 print(now)