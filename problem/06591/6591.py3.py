def Comb(a,b):
 if b>a//2: b=a-b
 ans=1
 i,j=a,1
 for k in range(b):
  ans=ans*i//j
  i-=1
  j+=1
 return ans

while 1:
 a,b=map(int,input().split())
 if a==b==0: break
 print(Comb(a,b))