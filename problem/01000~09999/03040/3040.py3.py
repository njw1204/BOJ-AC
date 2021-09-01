x=[int(input()),int(input()),int(input()),int(input()),int(input()),int(input()),int(input()),int(input()),int(input())]
for i1 in range(3):
 for i2 in range(i1+1,4):
  for i3 in range(i2+1,5):
   for i4 in range(i3+1,6):
    for i5 in range(i4+1,7):
     for i6 in range(i5+1,8):
      for i7 in range(i6+1,9):
       if x[i1]+x[i2]+x[i3]+x[i4]+x[i5]+x[i6]+x[i7]==100:
        print(x[i1],x[i2],x[i3],x[i4],x[i5],x[i6],x[i7],sep='\n')
        exit()