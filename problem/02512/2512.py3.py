n=int(input())
x=[*map(int,input().split())]
m=int(input())

left,right=1,min(m,max(x))
while left<right:
 mid,pay=(left+right+1)//2,0
 for i in x:
  pay+=i if i<mid else mid
 if pay<=m: left=mid
 else: right=mid-1
print(left)