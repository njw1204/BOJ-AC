import sys
sys.setrecursionlimit(10**4)

def solve(si,sj,minh,maxh):
    global n,field,height,visit,mid,succ,leftCnt,lv
    if field[si][sj][0]=="K": leftCnt-=1
    if leftCnt==0:
        return

    dd=[[si-1,sj],[si+1,sj],[si,sj-1],[si,sj+1],[si+1,sj+1],[si+1,sj-1],[si-1,sj+1],[si-1,sj-1]]

    for i,j in dd:
        if 0<=i<n and 0<=j<n and visit[i][j]!=lv and minh<=height[i][j]<=maxh:
            visit[i][j]=lv
            solve(i,j,minh,maxh)

        if leftCnt==0:
            return


n=int(input())
field=[]
height=[]
for i in range(n):
    field.append(list(input()))
for i in range(n):
    height.append([*map(int,input().split())])

all_heights=set()
leftCnt=0
for i in range(n):
    for j in range(n):
        if field[i][j]=="P":
            ppos=[i,j]
        if field[i][j]=="K":
            leftCnt+=1
        all_heights.add(height[i][j])
all_heights=sorted(all_heights)
sh=height[ppos[0]][ppos[1]]
ll=len(all_heights)

ans=10**18
lastShot=0
visit=[[0]*n for i in range(n)]
lv=1
for i in range(ll):
    j=lastShot
    while j<ll:
        minh,maxh=all_heights[i],all_heights[j]
        if minh<=sh<=maxh:
            lastShot=j
            if maxh-minh>ans:
                break
            succ=False
            tl=leftCnt
            solve(ppos[0],ppos[1],minh,maxh)
            lv+=1
            if leftCnt==0:
                leftCnt=tl
                ans=min(ans,maxh-minh)
                break
            leftCnt=tl
        j+=1

print(ans)