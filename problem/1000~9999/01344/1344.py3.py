import math
f=math.factorial

def Comb(a,b):
  return f(a)//f(b)//f(a-b)

a,b=int(input()),int(input())
a/=100
b/=100
ma=1-a
mb=1-b
asa,bsb=0,0
for i in [2,3,5,7,11,13,17]:
 asa+=Comb(18,i)*(a**i)*((1-a)**(18-i))
 bsb+=Comb(18,i)*(b**i)*((1-b)**(18-i))
print(1-(1-asa)*(1-bsb))