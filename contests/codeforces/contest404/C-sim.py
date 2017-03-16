from math import sqrt, ceil

n, m = map(int, raw_input().split(' '))

day = 0
storage = n

while (storage > 0):
    day+=1
    storage = min(n, storage + m)
    storage = storage - day

print day
