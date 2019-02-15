input()
s,p,a=0,0,0
for i in map(int,input().split()):
 s+=p
 a+=i*s
 p=i
print(a)