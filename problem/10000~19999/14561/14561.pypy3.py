def isPalin(A,N):
 numList=[]
 while A:
  numList.append(A%N)
  A//=N
 for n,i in enumerate(list(reversed(numList))):
  if i!=numList[n]: return 0
 return 1
 
for _ in range(int(input())):
 A,N=map(int,input().split())
 print(isPalin(A,N))