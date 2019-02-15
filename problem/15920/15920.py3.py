gu=1
st=0
input()
for i in input():
  if i=='W':
    gu+=1
    if gu==3: break
  else:
    if st==2: continue
    if gu==2: st=2
    else: st=(st+1)%2
if gu<3: print(0)
elif st==0: print(5)
elif st==1: print(1)
else: print(6)