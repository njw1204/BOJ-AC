import sys
input=sys.stdin.readline
n,m=map(int,input().split())
cnt=[0]*1000001
x=[]
for i in range(n):
    x.append(int(input()))
    cnt[x[i]]+=1
a=0
for i in range(1,1000001):
    cnt[i]+=cnt[i-1]
for i in x:
    if i>m: continue
    aa=cnt[m-i]
    if i+i<=m: aa-=1
    a+=aa
print(a//2)