import sys
n, m = map(int, raw_input().split())

A = set([])

for i in xrange(n):
    A.add(raw_input())

if len(A) > 2:
    print "NO"

if len(A) == 1:
    print "YES"

if len(A) == 2:
    if ("."*m) in A:
        print "YES"
    else:
        print "NO"
