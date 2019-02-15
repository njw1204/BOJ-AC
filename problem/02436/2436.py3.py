def GCD(a,b): return GCD(b,a%b) if b else a
def LCM(a,b): return a*b//GCD(a,b)

a,b=map(int,input().split())

m,n=1,b//a
ans1,ans2=0,0
while m*m<=b//a:
  n=b//a//m
  if (b//a)%m:
    m+=1
    continue
  if GCD(n,m)>1:
    m+=1
    continue
  if m*n==b//a:
    ans1,ans2=m*a,n*a
  m+=1
print(ans1,ans2)
