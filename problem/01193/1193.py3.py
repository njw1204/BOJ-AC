T=int(input())
i=0
while T-(i+1)>0:
 i+=1
 T-=i
i+=2
dir=i%2
if dir==1: print(T,i-T,sep='/')
else: print(i-T,T,sep='/')