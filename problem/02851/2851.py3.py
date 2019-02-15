prev,now=0,0
for i in range(10):
 prev=now
 now=prev+int(input())
 if now>=100: break
if 100-prev<abs(now-100): print(prev)
else: print(now)