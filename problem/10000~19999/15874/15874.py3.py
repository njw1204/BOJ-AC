k,s=map(int,input().split())
x=list(input())
for i in range(s):
  if x[i].isalpha() and x[i].isupper():
    print(chr(ord('A')+(ord(x[i])-ord('A')+k)%26),end='')
  elif x[i].isalpha():
    print(chr(ord('a')+(ord(x[i])-ord('a')+k)%26),end='')
  else:
    print(x[i],end='')