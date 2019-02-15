T,S=input(),0.0
for i in range(4):
 if chr(ord('A')+i) in T: S=4-i
if '+' in T: S+=0.3
if '-' in T: S-=0.3
print('%.1f'%S)