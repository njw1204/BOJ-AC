import sys
input=sys.stdin.readline

def update(fenwick,i,dx):
  while i<len(fenwick):
    fenwick[i]+=dx
    i+=i&-i

def sum(fenwick,i):
  s=0
  while i:
    s+=fenwick[i]
    i-=i&-i
  return s

ans=1
fenwick_cnt=[0]*200002
fenwick_len=[0]*200002

for i in range(int(input())):
  x=int(input())+1
  leftCnt,rightCnt=sum(fenwick_cnt,x-1),sum(fenwick_cnt,200001)-sum(fenwick_cnt,x)
  leftSum,rightSum=sum(fenwick_len,x-1),sum(fenwick_len,200001)-sum(fenwick_len,x)
  temp=((x-1)*leftCnt-leftSum)+(rightSum-(x-1)*rightCnt)
  if i:
    ans*=temp
    ans%=1000000007
  update(fenwick_cnt,x,1)
  update(fenwick_len,x,x-1)

print(ans)