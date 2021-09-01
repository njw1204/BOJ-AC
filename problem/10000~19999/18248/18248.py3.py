import sys
sys.setrecursionlimit(10**9)

def dfs(si):
    global n,m,a,mr,visit

    if visit[si]:
        if visit[si]==-1: return True
        return False

    visit[si]=-1
    for i in range(m):
        mym=a[si][i]
        if mym==1:
            for j in mr[i][0]:
                result=dfs(j)
                if result: return True

    visit[si]=1
    return False


n,m=map(int,input().split())
a=[]
mr=[[[] for j in range(2)] for i in range(m)]
visit=[0]*1000

for i in range(n):
    x=[*map(int,input().split())]
    a.append(x)
    for j in range(m):
        mr[j][x[j]].append(i)

for i in range(n):
    if dfs(i):
        print("NO")
        exit(0)

print("YES")