import re
print("SUBMARINE" if re.match("(100+1+|01)+$",input()) else "NOISE")