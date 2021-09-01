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
    global rlink,visit,result
    visit[si]=True
    result.append(si)
    for node in rlink[si]:
        if not visit[node]:
            rdfs(node)

v,e=map(int,input().split())
link=[[] for i in range(v+1)]
rlink=[[] for i in range(v+1)]

for i in range(e):
    x,y=map(int,input().split())
    link[x].append(y)
    rlink[y].append(x)

st=[]
visit=[False]*(v+1)
for i in range(1,v+1):
    if not visit[i]:
        dfs(i)

visit=[False]*(v+1)
total_result=[]
while st:
    i=st.pop()
    if not visit[i]:
        result=[]
        rdfs(i)
        result.sort()
        total_result.append(result)

total_result.sort(key=lambda x:x[0])
print(len(total_result))
for i in total_result:
    print(" ".join(map(str,i)), end=" -1\n")