x=[1]*3
for i in range(int(input())-2):x+=[(x[-1]+x[-3])%(10**9+9)]
print(x[-1])