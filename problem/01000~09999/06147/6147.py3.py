n,b=map(int,input().split())
d=[]
for i in range(n): d.append(int(input()))
d.sort(reverse=True)
a,s=0,0
for i in range(n):
    if a>=b: break
    a+=d[i]
    s+=1
print(s)