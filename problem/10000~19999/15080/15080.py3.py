h0,m0,s0=map(int,input().split(" : "))
h,m,s=map(int,input().split(" : "))
v=h*60*60+m*60+s-h0*60*60-m0*60-s0
print(v if v>=0 else v+86400)