ppprev,pprev,prev,now=0,1,1,1
n=int(input())
if n<4:
 print(1)
 exit()
for i in range(4,n+1):
 ppprev=pprev
 pprev=prev
 prev=now
 now=prev+ppprev
print(now)