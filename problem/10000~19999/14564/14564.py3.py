import sys
input=sys.stdin.readline
people,style,start=map(int,input().split())
while 1:
 call=int(input())
 if call==style//2+1:
  print(0)
  break
 move=call-(style//2+1)
 start=(start-1+move)%people+1
 print(start)