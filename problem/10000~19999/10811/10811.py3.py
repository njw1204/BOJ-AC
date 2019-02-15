n,m=map(int,input().split())
x=[i for i in range(1,n+1)]
for i in range(m):
    a,b=map(int,input().split())
    cnt=0
    for j in range(a-1,b):
        if j>=b-1-cnt: break
        x[j],x[b-1-cnt]=x[b-1-cnt],x[j]
        cnt+=1
for i in x: print(i,end=' ')