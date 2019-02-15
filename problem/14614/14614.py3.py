a,b,c=map(int,input().split())
even=False if c&1 else True
ans=0
w=1
while a+b:
  abit,bbit=a&1,b&1
  if abit==0 and bbit==1:
    if not even: ans+=w
  elif abit==1 and bbit==0:
    ans+=w
  elif abit==1 and bbit==1:
    if even: ans+=w
  w*=2
  a//=2
  b//=2
print(ans)