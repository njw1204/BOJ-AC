for t in range(int(input())):
 x=input()
 r=["0" for i in range(len(x))]
 lv=0
 for i in range(len(x)):
  for j in range(10):
   v=((10**i*j)+int("".join(r)))**3
   if v//(10**i)%10==int(x[-i-1]):
    r[-i-1]=str(j)
    break
 print(int("".join(r)))