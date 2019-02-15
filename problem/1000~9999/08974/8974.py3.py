x=[]
for i in range(1,46):
 for j in range(i): x.append(i)
a,b=map(int,input().split())
print(sum(x[a-1:b]))