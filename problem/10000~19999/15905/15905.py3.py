n=int(input())
x=[]
for i in range(n):
 x.append([*map(int,input().split())])
x.sort(key=lambda x:(-x[0],x[1]))
s=x[4][0]
a=0
for i in range(5,n):
 if x[i][0]==s: a+=1
print(a)