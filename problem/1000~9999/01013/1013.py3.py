import re
r=re.compile("(100+1+|01)+")
for i in range(int(input())):
 if r.fullmatch(input()):print("YES")
 else: print("NO")