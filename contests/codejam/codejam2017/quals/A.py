from functools import reduce
from Queue import PriorityQueue

def count_true(list):
    return reduce(lambda c, x: c + (1 if x == '+' else 0), list, 0)
    #x = 0
    #for i in list:
    #    if i == "+":
    #        x+=1
    #return x

class solver:
    def __init__(self, pancakes, K):
        self.pancakes = pancakes
        self.n = len(pancakes)
        self.k = K

    def solve(self):
        #if count_true(self.pancakes) == self.n: # already flipped
        #    return "0"
        #if self.k == len(self.pancakes): # not sorted, but can only flip all
        #    return "IMPOSSIBLE"

        #if (self.n % 2 != count_true(self.pancakes) % 2):
        #    return "IMPOSSIBLE"

        # actual algo
        past_states = set([])
        frontier = PriorityQueue()
        frontier.put((0, -1 * count_true(self.pancakes), self.pancakes))

        while not frontier.empty():
            state = frontier.get()
            #print state
            #raw_input()
            t_count = -1 * state[1]
            step = state[0]
            state = state[2]

            if t_count == self.n: # we done here, bfs guarantees shortest path
                return str(step)

            if state in past_states: # been here before
                #print "C"
                continue

            past_states.add(state)

            for x in xrange(0, self.n - self.k + 1):
                new_state = list(state)
                for i in xrange(self.k):
                    new_state[x + i] = "+" if new_state[x + i] == "-" else "-"
                frontier.put((step + 1, -1 * count_true(new_state), "".join(new_state)))

        return "IMPOSSIBLE"

if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(T):
        line = raw_input().split(" ")
        s = solver(line[0], int(line[1]))
        print "Case #%d: %s" % (i + 1, s.solve())
