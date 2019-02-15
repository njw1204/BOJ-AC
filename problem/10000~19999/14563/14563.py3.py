input()
x=[*map(int,input().split())]
for i in x:
 a=0
 for j in range(1,i//2+1):
  if i%j==0: a+=j
 if a>i: print('Abundant')
 elif a<i: print('Deficient')
 else: print('Perfect')