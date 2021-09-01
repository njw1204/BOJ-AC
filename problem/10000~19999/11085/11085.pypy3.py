from collections import deque

def solve(min_width):
    global p,w,c,v,link
    visit=[False]*1005
    Q=deque()

    visit[c]=True
    Q.append(c)
    while Q:
        i=Q.popleft()
        for j in link[i]:
            if j[1]>=min_width:
                if not visit[j[0]]:
                    visit[j[0]]=True
                    Q.append(j[0])
                    if j[0]==v: return True
    return False
    

p,w=map(int,input().split())
c,v=map(int,input().split())
link=[list() for i in range(1005)]
for i in range(w):
    s,e,width=map(int,input().split())
    link[s].append([e,width])
    link[e].append([s,width])
left,right=1,1000
while left<right:
    mid=(left+right+1)//2
    if solve(mid):
        left=mid
    else:
        right=mid-1
print(left)