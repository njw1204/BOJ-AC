for _ in range(int(input())):
 L=[*map(int,input().split())]
 n=0
 while n<len(L):
  if L[n]%2: del L[n]
  else: n+=1
 print(sum(L),min(L))