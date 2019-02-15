n=int(input())
s=input()
p=0
a=0
while p<n-1:
 if s[p]!=s[p+1]:
  a+=1
  p+=1
 p+=1
print(a)