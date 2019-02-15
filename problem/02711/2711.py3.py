for _ in range(int(input())):
 X,T=input().split()
 print(T[:int(X)-1]+T[int(X):])