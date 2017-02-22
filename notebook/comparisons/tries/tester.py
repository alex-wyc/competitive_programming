import random

n = 1000000
m = 1000000

f = open('/etc/dictionaries-common/words', 'r').read().split()

filtered_list = [s for s in f if s.isalnum()]

g = open('testfile', 'w')

g.write(str(n) + "\n")

for i in xrange(n):
    g.write(random.choice(filtered_list) + "\n")

g.write(str(m) + "\n")

for i in xrange(m):
    g.write(random.choice(filtered_list) + "\n")

g.close()
