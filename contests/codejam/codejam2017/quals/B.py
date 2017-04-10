if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(T):
        n = raw_input()
        result = ["" for x in xrange(len(n))]

        for j in xrange(len(n) - 1):
            #print result
            d1 = n[j]
            d2 = n[j+1]

            result[j] = d1

            if (d2 < d1): # breaks condition
                #print d1
                k = j
                #print k
                while (k >= 0 and n[k] == d1):
                    k-=1
                k += 1
                #print k
                result[k] = str(int(d1) - 1)
                k += 1
                while k < len(n):
                    result[k] = '9'
                    k+= 1
                break

        if result[-1] == "":
            result[-1] = n[-1]

        print "Case #%d: %s" % (i + 1, str(int("".join(result))))
