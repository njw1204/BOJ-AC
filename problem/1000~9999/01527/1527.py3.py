cnt=0
A,B=map(int,input().split())
leftLen,rightLen=len(str(A)),len(str(B))
for i in range(leftLen,rightLen+1):
  for j in range(2**i):
    out=0
    weight=1
    for k in range(i):
      if j%2: t=7
      else: t=4
      out+=t*weight
      j//=2
      weight*=10
    if A<=out<=B: cnt+=1
print(cnt)