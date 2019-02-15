n,b,w=map(int,input().split())
x=list(input())
ans,bCnt,wCnt,left,right=0,0,0,0,0
while left<n and right<n:
  if x[right]=='W':
    wCnt+=1
    if wCnt>=w: ans=max(ans,right-left+1)
    right+=1
  elif bCnt<b:
    bCnt+=1
    if wCnt>=w: ans=max(ans,right-left+1)
    right+=1
  else:
    if x[left]=='W': wCnt-=1
    else: bCnt-=1
    left+=1
    if left>n-1: break
    if right<left:
      wCnt,bCnt=0,0
      right=left
print(ans)