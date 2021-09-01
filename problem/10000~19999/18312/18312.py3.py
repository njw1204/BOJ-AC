n,k=map(int,input().split())
h,m,s=0,0,0
k=str(k)
a=0
while (h,m,s)<=(n,59,59):
    if k in str("%02d" % h) or k in str("%02d" % m) or k in str("%02d" % s):
        a+=1
    s+=1
    if s==60:
        s=0
        m+=1
    if m==60:
        m=0
        h+=1
print(a)