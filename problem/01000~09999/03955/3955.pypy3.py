from math import gcd

def extended_euclidean(a,b):
    if b==0: return (a,1,0)
    g,x,y=extended_euclidean(b,a%b)
    return (g,y,x-(a//b)*y)

for _ in range(int(input())):
    k,c=map(int,input().split())
    if c==1:
        if k+1>10**9: print("IMPOSSIBLE")
        else: print(k+1)
    elif k==1:
        print(1)
    elif gcd(k,c)!=1:
        print("IMPOSSIBLE")
    else:
        a=extended_euclidean(k,c)[2]
        if a<0: a+=k
        if a>10**9: print("IMPOSSIBLE")
        else: print(a)