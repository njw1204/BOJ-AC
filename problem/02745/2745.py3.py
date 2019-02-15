n,b=input().split()
radix,ans=1,0
for i in n[::-1]:
 if i>'9': s=ord(i)-ord('A')+10
 else: s=ord(i)-ord('0')
 ans+=s*radix
 radix*=int(b)
print(ans)