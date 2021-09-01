def dfs(s,w):
    global n,x,visit
    visit[s]=1
    vl=[]
    for i in range(n):
        if not visit[i] and x[s][-1]==x[i][0]==x[i][-1]:
            w+=len(x[i])
            visit[i]=1
            vl.append(i)
    mw=w
    for i in range(n):
        if not visit[i] and x[s][-1]==x[i][0]:
            mw=max(mw,dfs(i,w+len(x[i])))
    visit[s]=0
    for i in vl:
        visit[i]=0
    return mw

n=int(input())
x=[input() for i in range(n)]
ans=0
for i in range(n):
    visit=[0]*n
    ans=max(ans,dfs(i,len(x[i])))
print(ans)