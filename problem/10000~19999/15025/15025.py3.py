x,y=map(int,input().split())
if x==y==0:
 print("Not a moose")
 exit(0)
elif x==y:
 print(end="Even ")
else:
 print(end="Odd ")
print(max(x,y)*2)