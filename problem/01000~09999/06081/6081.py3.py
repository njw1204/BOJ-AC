n,q=map(int,input().split())
s=[0]*(n+1)
for i in range(1,n+1):
    s[i]=s[i-1]+int(input())
for i in range(q):
    x,y=map(int,input().split())
    print(s[y]-s[x-1])