t=[1 for i in range(36)]
N=int(input())
for i in range(2,N+1):
  t[i]=0
  for j in range(0,i):
    t[i]+=t[j]*t[i-1-j]
print(t[N])