
T =  int(raw_input())

for i in xrange(T):
    N = int(raw_input())
    heights = set([])
    for j in xrange(2 * N - 1):
        h = map(int, raw_input().split())
        for hh in h:
            if hh in heights:
                heights.remove(hh)
            else:
                heights.add(hh)

    heights = list(heights)
    heights.sort()
    print "Case #%d: %s" % ((i + 1), " ".join(map(str, heights)))
