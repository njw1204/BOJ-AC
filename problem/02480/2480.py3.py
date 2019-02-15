max_cost = 0
s = list(map(int,input().split()))
if len(set(s)) == 3:
  max_cost = max((max(s)*100,max_cost))
elif len(set(s)) == 1:
  max_cost = max((10000+s[0]*1000,max_cost))
else:
  if s.count(s[0]) == 2: max_cost = max((1000+s[0]*100,max_cost))
  else: max_cost = max((1000+s[1]*100,max_cost))
print(max_cost)