import sys
input=sys.stdin.readline

def solve(m):
    global x,k
    a=0
    for i in x:
        if m>i: a+=m-i
    return a<=k

n,k=map(int,input().split())
x=[]
for i in range(n):
    x.append(int(input()))

left,right=min(x),min(x)+k
while left<right:
    mid=(left+right+1)//2
    if solve(mid): left=mid
    else: right=mid-1
print(left)