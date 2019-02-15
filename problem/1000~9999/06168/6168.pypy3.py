import sys
input=sys.stdin.readline
n=int(input())
c=0
x=[]
for i in range(n):
    x.append(int(input()))
    if x[i]==1: c+=1
a=min(c,n-c)
ac=0
for i in range(n):
    if x[i]==1: c-=1
    else: ac+=1
    a=min(a,ac+c)
print(a)