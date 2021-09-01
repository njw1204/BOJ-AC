d={}
for i in range(int(input())):
 x=input()
 d[x]=d.get(x,0)+1
print(sorted(d.items(),key=lambda x:(-x[1],x[0]))[0][0])