n,m=map(int,input().split())
npx,npy,now_dir=1,1,1

while n>1:
    siz=n*n
    if m<=siz//4:
        next_dir=[3,2,1,0][now_dir]
        dx=[0]*4
        dy=dx
    elif m<=siz//4*2:
        next_dir=now_dir
        dx=[-(n//2),0,n//2,0]
        dy=dx[::-1]
    elif m<=siz//4*3:
        next_dir=now_dir
        dx=[-(n//2),n//2,n//2,-(n//2)]
        dy=dx
    else:
        next_dir=[1,0,3,2][now_dir]
        dx=[-(n//2-1),n-1,(n//2-1),-(n-1)]
        dy=dx[::-1]

    npx+=dx[now_dir]
    npy+=dy[now_dir]
    n//=2
    m=(m-1)%(siz//4)+1
    now_dir=next_dir

print(npx,npy)