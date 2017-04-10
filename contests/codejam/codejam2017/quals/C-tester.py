import random as r

NBound = 1e18
T = 100

f = open("c-large-sample.in", 'w')

f.write(str(T) + "\n")

for i in xrange(T):
    n = r.randint(0, NBound)
    k = r.randint(0, n)
    f.write("%d %d\n" % (n, k))

f.close()

