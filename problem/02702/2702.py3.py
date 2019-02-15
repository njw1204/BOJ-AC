def gcd(a,b): return gcd(b,a%b) if b>0 else a
def lcm(a,b): return a*b//gcd(a,b)
for _ in range(int(input())):
 A,B=map(int,input().split())
 print(lcm(A,B),gcd(A,B))