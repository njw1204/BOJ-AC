def ccw(a,b,c):
	d=a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-b[0]*a[1]-c[0]*b[1]-a[0]*c[1]
	if d>0: return 1
	elif d<0: return -1
	else: return 0

x=[]
for i in range(3):
	x.append([*map(int,input().split())])
print(ccw(x[0],x[1],x[2]))