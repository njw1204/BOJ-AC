def gcd(a,b):
 return gcd(b,a%b) if b else a

def lcm3(a,b,c):
 return a*b*c*gcd(gcd(a,b),c)//gcd(a,b)//gcd(b,c)//gcd(a,c)

x=[*map(int,input().split())]
r=100**5
for i in range(5):
 for j in range(i+1,5):
  for k in range(j+1,5):
   n=lcm3(x[i],x[j],x[k])
   r=min(n,r)
print(r)