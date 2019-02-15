k,n=map(int,input().split())
x=[]
for i in range(k): x.append(int(input()))
left,right=1,max(x)
while left<right:
 mid=(left+right+1)//2
 c=0
 for i in x: c+=i//mid
 if c>=n: left=mid
 else: right=mid-1
print(left)