import sys
input=sys.stdin.readline

ans,ansCnt=0,0
d={}
for i in range(int(input())):
 n=int(input())
 d[n]=d.get(n,0)+1
 if d[n]>ansCnt or d[n]==ansCnt and n<ans:
  ans,ansCnt=n,d[n]
print(ans)