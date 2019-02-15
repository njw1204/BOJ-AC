def ans(x):
  r=0
  w=1
  while x//w:
    r+=(x//w)*(w-w//2)
    w*=2
  return r

a,b=map(int,input().split())
print(ans(b)-ans(a-1))