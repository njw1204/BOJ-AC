import sys
input=sys.stdin.readline
n=int(input())
x=[0]*n
pos=dict()

for i in range(n):
    t=int(input())*511111+i
    x[i]=t
    pos[t]=i

y=sorted(x)
a=0
for nn,i in enumerate(y):
    a=max(a,pos[i]-nn)
print(a+1)