base=11*60*24+11*60+11
d,h,m=map(int,input().split())
fin=d*60*24+h*60+m
print((fin-base) if fin>=base else -1)