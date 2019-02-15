r=[]
for _ in range(int(input())):
    n,z,y,x=input().split()
    x,y,z=int(x),int(y),int(z)
    r.append((x,y,z,n))
r.sort()
print(r[-1][3])
print(r[0][3])