for _ in range(int(input())):
  x,y=input(),input()
  a=0
  for i in range(len(x)):
    if x[i]!=y[i]: a+=1
  print('Hamming distance is %d.'%a)