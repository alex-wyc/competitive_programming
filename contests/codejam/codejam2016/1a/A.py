
T = int(raw_input())

for i in xrange(T):
    word = raw_input()
    result = word[0]

    for j in xrange(1, len(word)):
        if word[j] >= result[0]:
            result = word[j] + result
        else:
            result = result + word[j]

    print "Case #%d: %s" % ((i + 1), result)
