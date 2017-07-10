def get_closest_scores(Cstr, Jstr):
    cpossibilities = []
    jpossibilities = []

    for i in xrange(len(Cstr) - 1, -1, -1):


if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(T):
        [C, J] = raw_input().split()
        (C, J) = get_closest_scores(C, J)
        print C
        print J
        print "==="
