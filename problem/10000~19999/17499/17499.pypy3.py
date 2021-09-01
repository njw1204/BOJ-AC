import sys
input=sys.stdin.readline
n,q=map(int,input().split())
a=[*map(int,input().split())]
shift=0
for i in range(q):
    op=[*map(int,input().split())]
    if op[0]==2:
        shift-=op[1]
        if shift<0: shift+=n
    elif op[0]==3:
        shift+=op[1]
        if shift>=n: shift-=n
    else:
        idx=(op[1]-1+shift)%n
        a[idx]+=op[2]
for i in range(n):
    print(a[(i+shift)%n], end=" ")