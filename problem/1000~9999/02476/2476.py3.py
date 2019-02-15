max_cost=0
for _ in range(int(input())):
 s=list(map(int,input().split()))
 if len(set(s))==3:
  max_cost = max(s)*100 if max(s)*100>max_cost else max_cost
 elif len(set(s))==1:
  max_cost = 10000+s[0]*1000 if 10000+s[0]*1000>max_cost else max_cost
 else:
  if s.count(s[0])==2:
   max_cost = 1000+s[0]*100 if 1000+s[0]*100>max_cost else max_cost
  else:
   max_cost = 1000+s[1]*100 if 1000+s[1]*100>max_cost else max_cost
print(max_cost)