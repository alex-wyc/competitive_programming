class solver:
    def __init__(self, pancakes):
        self.pancakes = [p == "+" for p in pancakes]

    def solve(self):
        i = len(self.pancakes) - 1

        flip = 0

        while (i >= 0):
            if not self.pancakes[i]:
                for j in xrange(i + 1):
                    self.pancakes[j] = not self.pancakes[j]
                flip += 1

            i-=1

        return flip


if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(T):
        s = solver(raw_input())
        print "Case #%d: %d" % (i + 1, s.solve())
