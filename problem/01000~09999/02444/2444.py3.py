ans=[]
n=int(input())
m,j=n*2-1,1
for i in range(1,n*2):
 ans+=' '*((m-j)//2)+'*'*j+'\n'
 if i<n: j+=2
 else: j-=2
print(''.join(ans))