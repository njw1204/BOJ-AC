x,y=input(),input()
while x!=y and y:
 if y[-1]=='A': y=y[:-1]
 else: y=y[-2::-1]
print(+(x==y))