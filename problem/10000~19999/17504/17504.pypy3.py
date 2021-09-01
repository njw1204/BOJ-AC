import math
n=int(input())
x=list(map(int,input().split()))

a,b=x[n-2],x[n-1]
c=a*b+1
gcd=math.gcd(b,c)
b//=gcd
c//=gcd
top,down=b,c

for i in range(n-3,-1,-1):
    top=x[i]*down+top
    gcd=math.gcd(top,down)
    top//=gcd
    down//=gcd
    top,down=down,top

top=down-top
gcd=math.gcd(top,down)
top//=gcd
down//=gcd
print(top,down)