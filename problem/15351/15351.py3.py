for i in range(int(input())):
  s=0
  for j in input():
    if j==' ': continue
    s+=ord(j)-ord('A')+1
  if s==100: print('PERFECT LIFE')
  else: print(s)