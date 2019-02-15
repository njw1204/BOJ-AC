X=[]
for _ in range(5): X.append(int(input()))
print(min(X[0]*X[4],X[1]+(X[4]-X[2])*X[3] if X[4]>X[2] else X[1]))