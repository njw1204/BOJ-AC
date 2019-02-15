sel=[True]*10001
for i in range(1,10000):
  t=i
  while t:
    i+=t%10
    t//=10
  if i>10000: continue
  sel[i]=False
for i in range(1,10001):
  if sel[i]: print(i)