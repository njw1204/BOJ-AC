def dfs(a,w):
    global b,ans
    if a>=b:
        if a==b: ans=min(ans,w)
        return
    dfs(a*2,w+1)
    dfs(a*10+1,w+1)

a,b=map(int,input().split())
ans=10**9
dfs(a,1)
print(ans if ans<10**9 else -1)