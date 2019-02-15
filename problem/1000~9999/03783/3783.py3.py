from decimal import *
getcontext().prec=300
getcontext().rounding=ROUND_FLOOR
for _ in range(int(input())):
 print((Decimal(input())**(Decimal('.'+'3'*299+'4'))).quantize(Decimal('.'+'0'*9+'1')))