x,y=map(int,input().split())
a,b=map(int,input().split())
w=["Persepolis", "Esteghlal"]
if x+b>y+a:
 print(w[0])
elif x+b<y+a:
 print(w[1])
elif b>y:
 print(w[0])
elif b<y:
 print(w[1])
else:
 print("Penalty")