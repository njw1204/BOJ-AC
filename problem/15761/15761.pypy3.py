input()
w=0
for i in sorted(map(int,input().split()))[::-1]:
 if w<=i: w+=1
print(w)