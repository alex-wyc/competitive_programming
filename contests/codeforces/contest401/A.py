n = int(raw_input())
x = int(raw_input())

content = [False, False, False]

content[x] = True

n = n % 6

if n % 2 == 1:
    tmp = content[1]
    content[1] = content[0]
    content[0] = tmp
    n-=1

for i in xrange(n / 2):
    tmp = content[2]
    content[2] = content[1]
    content[1] = content[0]
    content[0] = tmp

for i in xrange(3):
    if content[i]:
        print i

