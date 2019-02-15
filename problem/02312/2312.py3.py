import sys
input=sys.stdin.readline
for _ in range(int(input())):
  x=int(input())
  i=2
  while x>1:
    cnt=0
    while x%i==0:
      x//=i
      cnt+=1
    if cnt: print(i,cnt)
    i+=1