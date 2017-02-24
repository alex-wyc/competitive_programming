from math import sqrt

n = int(raw_input()) + 1

if n < 4:
    print "1"
    str = ""
    for i in xrange(n - 1):
        str += " 1"
    print str[1:]
    exit(0)

a = [1 for x in xrange(n - 1)]

limit = int(sqrt(n)) + 1

for i in xrange(2, limit + 1):
    if (a[i - 2] == 1):
        j = i * i
        while j < n + 1:
            a[j - 2] = 0
            j = j + i

print 2

output = ""

for i in xrange(n - 1):
    if a[i] == 0:
        output += " 1"
    else:
        output += " 2"

print output[1:]
