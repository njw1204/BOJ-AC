input()
ans,num_sum=0,0
for i in map(int,input().split()):
 ans+=num_sum*i
 num_sum+=i
print(ans)