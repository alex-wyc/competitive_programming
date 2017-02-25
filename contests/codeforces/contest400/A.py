targets = set(raw_input().split())

days = int(raw_input())

for i in xrange(days):
    print " ".join(targets)
    names = raw_input().split()
    targets.remove(names[0])
    targets.add(names[1])

print " ".join(targets)
