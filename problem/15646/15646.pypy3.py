import sys
input=sys.stdin.readline

def update(fenwick,si,sj,dx,height,width):
  i=si
  while i<height:
    j=sj
    while j<width:
      fenwick[i][j]+=dx
      j+=j&-j
    i+=i&-i

def sum(fenwick,si,sj):
  s=0
  i=si
  while i:
    j=sj
    while j:
      s+=fenwick[i][j]
      j-=j&-j
    i-=i&-i
  return s

N,M,Q=map(int,input().split())
fenwick=[[0]*(M+2) for i in range(N+2)]

for i in range(Q):
  cmd=[*map(int,input().split())]
  if cmd[0]==1:
    op,x1,y1,x2,y2,d=cmd
    update(fenwick,x1,y1,d,N+2,M+2)
    update(fenwick,x2+1,y1,-d,N+2,M+2)
    update(fenwick,x1,y2+1,-d,N+2,M+2)
    update(fenwick,x2+1,y2+1,d,N+2,M+2)
  else:
    op,x,y=cmd
    print(sum(fenwick,x,y))