import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**8)

def dfs(si):
    global n,m,like_range,match,visit
    visit[si]=True
    min_book,max_book=like_range[si]
    for i in range(min_book,max_book+1):
        if not match[i] or not visit[match[i]] and dfs(match[i]):
            match[i]=si
            return 1
    return 0

for _ in range(int(input())):
    n,m=map(int,input().split())
    like_range=[[] for i in range(m+1)]
    for i in range(m):
        like_range[i+1]=[*map(int,input().split())]
    match=[0]*(n+1)
    ans=0
    for i in range(1,m+1):
        visit=[False]*(m+1)
        ans+=dfs(i)
    print(ans)