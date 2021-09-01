def GetDivisior(num):
 global o
 i=1
 while i*i<=num:
  if num%i==0:
   o[i]=o.get(i,0)+1
   if num//i!=i: o[num//i]=o.get(num//i,0)+1
  i+=1

n=int(input())
o=dict()
for i in map(int,input().split()): GetDivisior(i)
for i,c in sorted(o.items()):
 if c==n: print(i)