def gcd(a,b): return gcd(b,a%b) if b else a
a,b=map(int,input().split())
for i in range(1,gcd(a,b)+1):
 if a%i==0 and b%i==0: print(i,a//i,b//i)