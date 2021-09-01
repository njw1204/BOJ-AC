n,w,h,l=map(int,input().split())
ww,hh=w//l,h//l
print(min(n,ww*hh))