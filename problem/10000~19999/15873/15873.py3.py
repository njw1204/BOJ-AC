x=input()
if x=='1010': print(20)
elif x[:2]=='10': print(int(x[2:])+10)
elif x[-2:]=='10': print(int(x[:-2])+10)
else: print(int(x[0])+int(x[1]))