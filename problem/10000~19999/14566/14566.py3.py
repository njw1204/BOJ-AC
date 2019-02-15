n=int(input())
x=sorted([*map(int,input().split())])
mini=99999999
mini_cnt=0
for i in range(n-1):
 if abs(x[i]-x[i+1])<mini:
  mini=abs(x[i]-x[i+1])
  mini_cnt=1
 elif abs(x[i]-x[i+1])==mini:
  mini_cnt+=1
print(mini,mini_cnt)