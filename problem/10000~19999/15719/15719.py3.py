import re
import sys
number = int(sys.stdin.readline())
digits = re.compile(r'\d+', re.ASCII)
print(sum(int(m.group()) for m in digits.finditer(sys.stdin.read())) - (number - 1) * number // 2)