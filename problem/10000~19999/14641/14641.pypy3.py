n,m=map(int,input().split())
li=[[0]*128 for i in range(128)]
for i in range(n):
 a,b=input().split()
 li[ord(a)][ord(b)]=1
for i in range(128):
 for j in range(128):
  for k in range(128):
   if li[j][i] and li[i][k]: li[j][k]=1
for i in range(m):
 a,b=input().split()
 if len(a)!=len(b):
  print("no")
 else:
  fail=False
  for j in range(len(a)):
   if a[j]!=b[j] and not li[ord(a[j])][ord(b[j])]:
    print("no")
    fail=True
    break
  if not fail: print("yes")