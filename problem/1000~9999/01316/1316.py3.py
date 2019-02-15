ans=0
for _ in range(int(input())):
 T=input()
 used,ch,fail=[],0,False
 for i in T:
  if i!=ch:
   if i in used:
    fail=True
    break
   else:
    ch=i
    used+=i
 if not fail: ans+=1
print(ans)