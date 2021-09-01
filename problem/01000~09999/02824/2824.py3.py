def gcd(m,n):
    while n>0:
        t=m%n
        m=n
        n=t
    return m

input();A=list(map(int,input().split()))
input();B=list(map(int,input().split()))

AA=1; BB=1
for i in A: AA*=i
for i in B: BB*=i
result=gcd(AA,BB)
if result >= 10**9: print("%09d" % (result%(10**9)))
else: print(result)