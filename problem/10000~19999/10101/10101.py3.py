T=[int(input()) for i in range(3)]
if sum(T)!=180: print("Error")
else: print(["Equilateral","Isosceles","Scalene"][len(set(T))-1])