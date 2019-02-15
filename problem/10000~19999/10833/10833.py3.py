a=0
for i in range(int(input())):
  b,c=map(int,input().split())
  a+=c%b
print(a)