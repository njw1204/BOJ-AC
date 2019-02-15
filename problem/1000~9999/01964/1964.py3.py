ans=5
for i in range(2,int(input())+1):
 ans+=i*3+1
 ans%=45678
print(ans)