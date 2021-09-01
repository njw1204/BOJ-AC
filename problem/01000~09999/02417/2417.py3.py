x=int(input())
l,r=0,x
while l<r:
 m=(l+r)//2
 if m*m>=x:r=m
 else:l=m+1
print(l)