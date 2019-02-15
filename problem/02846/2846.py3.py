ans,last,temp=0,-1,0
input()
for i in map(int,input().split()):
  if i>last and last!=-1: temp+=i-last
  else: temp=0
  if temp>ans: ans=temp
  last=i
print(ans)