n,m=map(int,input().split())
x=[*map(int,input().split())]
left,right=0,max(x)-1
while left<right:
 mid=(left+right+1)//2
 namu=0
 for i in x: namu+=i-mid if i-mid>0 else 0
 if namu>=m: left=mid
 else: right=mid-1
print(left)