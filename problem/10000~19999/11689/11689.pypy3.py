import itertools
from math import gcd

def lcm_two(x,y):
    return x*y//gcd(x,y)

def lcm(li):
    a=1
    for i in li:
        a=lcm_two(a,i)
    return a

n=int(input())
i=2
a=set()
while i*i<=n:
    if n%i==0:
        a.add(i)
        a.add(n//i)
    i+=1
a.add(n)
ta=a
a=sorted(a)

xxx=set()
for i in range(len(a)):
    if a[i] in xxx: continue
    for j in range(i+1,len(a)):
        if a[j]%a[i]==0:
            xxx.add(a[j])

for i in xxx:
    ta.remove(i)
a=sorted(ta)

ans=0
for i in range(1,len(a)+1):
    for j in itertools.combinations(a,i):
        ans+=pow(-1,i-1)*(n//lcm(j))

if n==1: print(1)
else: print(n-ans)