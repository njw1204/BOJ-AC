import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**8)

def dfs(si):
    global link,st,visit
    visit[si]=True
    for node in link[si]:
        if not visit[node]:
            dfs(node)
    st.append(si)

def rdfs(si):
    global link,visit
    visit[si]=True
    for node in link[si]:
        if not visit[node]:
            rdfs(node)

n,m=map(int,input().split())
link=[[] for i in range((n+1)*(m+1))]

for i in range(n):
    for idx,j in enumerate(input()):
        cur_node=i*m+idx
        if j=="N":
            link[cur_node].append(cur_node-m)
            link[cur_node-m].append(cur_node)
        if j=="W":
            link[cur_node].append(cur_node-1)
            link[cur_node-1].append(cur_node)
        if j=="E":
            link[cur_node].append(cur_node+1)
            link[cur_node+1].append(cur_node)
        if j=="S":
            link[cur_node].append(cur_node+m)
            link[cur_node+m].append(cur_node)

st=[]
visit=[False]*((n+1)*(m+1))
for i in range(n*m):
    if not visit[i]:
        dfs(i)

visit=[False]*((n+1)*(m+1))
total_result=0
while st:
    i=st.pop()
    if not visit[i]:
        rdfs(i)
        total_result+=1
print(total_result)