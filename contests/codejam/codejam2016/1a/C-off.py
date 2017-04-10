import itertools
# The F parameter is the list of BFF identifiers, but 0-based (subtracting 1 from the input).
def cc(F):
  n = len(F)
  r = 0
  # Iterate over all possible orderings of the n kids.
  for O in itertools.permutations(xrange(n)):
    first = O[0]
    second = O[1]
    for i in xrange(1, n):  # Iterate over the permutation, skipping the first.
      # Check if i can be the last one by checking it and the first.
      prev = O[i - 1]
      cur = O[i]
      if ((F[cur] == first or F[cur] == prev) and
          (F[first] == cur or F[first] == second)):
        r = max(r, i + 1)
      # Check if i can be in the middle, and stop if it can't.
      if F[cur] != prev and (i == n - 1 or F[cur] != O[i + 1]):
        break
  return r

T = int(raw_input())
for i in xrange(T):
    N = int(raw_input())
    F = map(lambda s: int(s) - 1, raw_input().split())
    print "Case #%d: %d" % (i + 1, cc(F))
