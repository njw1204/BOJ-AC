import math
c=[0 for i in range(10)]
for i in input().replace('9','6'): c[int(i)]+=1
c[6]=math.ceil(c[6]/2)
print(max(c))