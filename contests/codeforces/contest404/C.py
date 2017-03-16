from math import sqrt, ceil
from decimal import *

getcontext().prec = 1000 # b/c annoying...
getcontext().rounding = ROUND_CEILING

n, m = map(Decimal, raw_input().split(' '))

if n < m:
    print n
else:
    print "%d" % (((Decimal(-1) + (Decimal(1) + Decimal(8) * (n -
        m)).sqrt()) / Decimal(2)).quantize(Decimal(1)) + m)
