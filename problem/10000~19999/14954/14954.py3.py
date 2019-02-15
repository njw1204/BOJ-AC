isCheck=[0]*800

def f(x):
 s=0
 while x:
   s+=(x%10)**2
   x//=10
 return s

n=int(input())
t=n
while True:
  n=f(n)
  if isCheck[n]:
    print('UNHAPPY')
    exit()
  elif n==1:
    break
  isCheck[n]=True
print('HAPPY')