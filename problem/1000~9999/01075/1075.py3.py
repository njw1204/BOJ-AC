N=int(input())//100*100
F=int(input())
while 1:
 if N%F==0:
  print(str(N)[-2:])
  break
 N+=1