d=["TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"]
for _ in range(int(input())):
 v=input()
 x=[0]*8
 for i in range(0,38):
  for j in range(8):
   if v[i:i+3]==d[j]:x[j]+=1
 for i in range(8):print(x[i],end=" ")
 print()