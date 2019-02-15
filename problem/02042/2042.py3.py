import sys
input=sys.stdin.readline

def P_update(i,n):
 global x
 l=len(x)
 while i<l:
  x[i]+=n
  i+=i&-i

def P_sum(i):
 global x
 s=0
 while i>0:
  s+=x[i]
  i-=i&-i
 return s

n,m,k=map(int,input().split())
x=[0]*(n+1)
for i in range(1,n+1):
 P_update(i,int(input()))
 
for i in range(m+k):
 o,a,b=map(int,input().split())
 if o==1:
  diff=b-(P_sum(a)-P_sum(a-1))
  P_update(a,diff)
 else: print(P_sum(b)-P_sum(a-1))