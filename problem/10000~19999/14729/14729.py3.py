import sys
input=sys.stdin.readline
li=[0]*100001
for i in range(int(input())):
  x=float(input())
  li[int(x*1000)]+=1
cnt=0
for i in range(100001):
  for j in range(li[i]):
    cnt+=1
    print('%.3f' % (i/1000))
    if cnt==7: exit(0)