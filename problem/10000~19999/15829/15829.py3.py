input()
x=input()
r,m,a=1,1234567891,0
for i in range(len(x)):
 a=(a+(ord(x[i])-ord('a')+1)*r)%m
 r=r*31%m
print(a)