import sys
input=sys.stdin.readline
alpha=set()
for i in range(ord('A'),ord('Z')+1):
  alpha.add(chr(i))
for i in range(int(input())):
  x=set(input())
  ans=alpha-x
  pr=0
  for i in ans:
    pr+=ord(i)
  print(pr)