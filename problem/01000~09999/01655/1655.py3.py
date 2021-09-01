import sys
x=[]
for i in range(int(input())):
 num=int(sys.stdin.readline())
 left,right=0,i-1
 while left<=right:
  mid=(left+right)//2
  if x[mid]>num:
   if left==right: break
   right=mid
  else: left=mid+1
 x.insert(left,num)
 print(x[i//2])