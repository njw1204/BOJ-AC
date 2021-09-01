def gcd(a,b): return a if b==0 else gcd(b,a%b)

A,B,C,D=*map(int,input().split()),*map(int,input().split())
E,F=A*D+C*B,B*D
G=gcd(E,F)
print(E//G,F//G)