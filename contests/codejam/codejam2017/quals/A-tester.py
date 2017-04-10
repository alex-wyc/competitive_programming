import random as r

f = open("A-large-test.in", 'w')

f.write("100\n")

for i in xrange(100):
    state = ""
    length = r.randint(2, 1000)
    for j in xrange(length):
        state += r.choice(['+', '-'])

    k = r.randint(2, length)

    f.write("%s %d\n" % (state, k))

f.close()
