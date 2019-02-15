import sys
input=sys.stdin.readline
k=int(input())

for _ in range(int(input())):
    m,n=map(int,input().split())
    min_mn=min(m,n)
    real_k=k-min_mn
    m,n=m-min_mn,n-min_mn

    if m>n:
        base=real_k//2+1
        if m>base: print(0)
        else: print(1)
    elif m<n:
        base=(real_k+1)//2
        if n>base: print(0)
        else: print(1)
    else: print(1)
