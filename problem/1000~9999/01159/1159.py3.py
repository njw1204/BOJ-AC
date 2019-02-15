L,fail={},True
for _ in range(int(input())):
 C=input()[0]
 L[C]=L.get(C,0)+1
for i in sorted(L.items()):
 if i[1]>=5:
  print(i[0],end='')
  fail=False
if fail: print("PREDAJA")