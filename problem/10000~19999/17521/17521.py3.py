n,w=map(int,input().split())
a,c=[int(input()) for i in range(n)],0
for i in range(n-1):
 if a[i]<a[i+1]:
  b=w//a[i]
  c+=b
  w-=a[i]*b
 else:
  w+=a[i]*c
  c=0
w+=a[n-1]*c
print(w)