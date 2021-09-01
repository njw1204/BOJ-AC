n=int(input())
s=input()
s=list(s)
for i in range(n):
 if s[i]=="?" :
  if s[n-i-1]=="?":
   s[i]=s[n-i-1]="a"
  else:
   s[i]=s[n-i-1]
 elif s[n-i-1]=="?":
   s[n-i-1]=s[i]
print("".join(s))