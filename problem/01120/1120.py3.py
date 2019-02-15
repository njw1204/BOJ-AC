a,b=input().split()
r=50
for i in range(len(b)-len(a)+1):
 t=0
 for j in range(len(a)):
  if a[j]!=b[i+j]: t+=1
 r=min(r,t)
print(r)