D,M=map(int,input().split())
X=[0,31,28,31,30,31,30,31,31,30,31,30,31]
ans=["Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"]
diff=D-1
for i in range(1,M): diff+=X[i]
print(ans[diff%7])