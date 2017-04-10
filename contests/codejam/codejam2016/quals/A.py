class solver:
    def __init__(self, n):
        self.digits = set([0,1,2,3,4,5,6,7,8,9])
        self.n = n

    def update_digits(self, n):
        while n >= 10:
            d = n % 10
            self.digits.discard(d)
            n = n / 10
        self.digits.discard(n)

    def solve(self):
        if (self.n == 0):
            return "INSOMNIA"
        
        x = self.n

        while len(self.digits) != 0:
            self.update_digits(x)
            x = x + self.n

        return str(x - self.n)


if __name__ == "__main__":
    t = int(raw_input())
    for i in xrange(t):
        s = solver(int(raw_input()))
        print "Case #%d: %s" % ((i + 1), s.solve())
