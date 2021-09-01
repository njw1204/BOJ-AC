for _ in range(int(input())):
 v,e=input().split()
 v=float(v)
 if e=="kg":print("%.4f"%(v*2.2046),"lb")
 if e=="lb":print("%.4f"%(v*0.4536),"kg")
 if e=="l":print("%.4f"%(v*0.2642),"g")
 if e=="g":print("%.4f"%(v*3.7854),"l")