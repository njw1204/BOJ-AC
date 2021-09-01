import sys
input=sys.stdin.readline

n,m=map(int,input().split())
link=[[] for i in range(n+1)]
for i in range(m):
    u,v=map(int,input().split())
    link[u].append(v)
    link[v].append(u)
k=int(input())
fire=set(map(int,input().split()))

ans=[]
for node in fire:
    succ=True
    for anode in link[node]:
        if anode not in fire:
            succ=False
            break
    if succ:
        ans.append(node)

fireCheck=set()
for node in ans:
    fireCheck.add(node)
    for anode in link[node]:
        fireCheck.add(anode)

if fire==fireCheck:
    print(len(ans))
    print(" ".join(map(str,ans)))
else:
    print(-1)