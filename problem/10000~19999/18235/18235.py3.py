import sys
sys.setrecursionlimit(10**6)

def dfs(day,a,b):
    global n,dist
    mv=2**(day-1)
    curr=dist//(2**day)%2

    if curr==0:
        ans=10**9
        aa,bb=a+mv,b+mv
        if 1<=aa<=n and 1<=bb<=n:
            ans=min(ans,dfs(day+1,aa,bb))
        aa,bb=a-mv,b-mv
        if 1<=aa<=n and 1<=bb<=n:
            ans=min(ans,dfs(day+1,aa,bb))
        return ans
    else:
        aa,bb=a+mv,b-mv
        if aa==bb:
            return day
        return dfs(day+1,aa,bb)


n,a,b=map(int,input().split())
a,b=min(a,b),max(a,b)
dist=abs(a-b)
if dist%2==1:
    print(-1)
    exit(0)
x=dfs(1,a,b)
print(x if x<10**9 else -1)