def gcd(a,b):
  while b>0:
    t=a%b
    a=b
    b=t
  return a

def lcm(a,b):
  return a*b//gcd(a,b)

a,b=map(int,input().split())
print(gcd(a,b),lcm(a,b),sep='\n')