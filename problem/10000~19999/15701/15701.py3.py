n=int(input())
i=1
a=0
while i*i<n:
 if n%i==0: a+=2
 i+=1
if n%(i*i)==0: a+=1
print(a)