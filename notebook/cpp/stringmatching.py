# string matching algos tester

import random
from string import ascii_letters, digits

candidates = ascii_letters + digits

N = 1000
M = 10000

f = open('testfile', 'w')
g = open('correct.output', 'w')

f.write(str(N) + '\n')

for i in xrange(N):
    length = random.randrange(0, M)
    str1 = "".join(random.choice(candidates) for _ in xrange(length))
    length2 = random.randrange(0, length)

    if random.randrange(0, 2) == 0: # match exists.. lol this is random
        starting = random.randrange(0, length - length2)
        str2 = str1[starting:starting + length2]
        g.write(str(starting) + '\n')

    else:
        str2 = "".join(random.choice(candidates) for _ in xrange(length2))
        g.write("-1\n")

    f.write("%s %s\n" % (str1, str2))

f.close()
g.close()
