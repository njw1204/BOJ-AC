import sys
input=sys.stdin.readline
n=int(input())
x=[0]*n
for i in range(n):
    x[i]=int(input())
bitcnt=[[0]*2 for i in range(20)]

for i in x:
    bit=1
    for j in range(20):
        if i&bit: bitcnt[j][1]+=1
        else: bitcnt[j][0]+=1
        bit<<=1

ans=0
for i in x:
    bit=1
    for j in range(20):
        if i&bit: base=0
        else: base=1
        ans+=bitcnt[j][base]*bit
        bit<<=1

print(ans//2)