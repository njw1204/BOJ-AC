n,a,b,c,d=map(int,input().split())
s=10**9
for i in range(1001):
 if a*i>=n:
  s=min(s,b*i)
 if c*i>=n:
  s=min(s,d*i)
print(s)