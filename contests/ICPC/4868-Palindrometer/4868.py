import sys

def palidrome_check(n, N):
    s = str(n)
    if (len(s) != N):
        s = "0" * (N - len(s)) + s
    return s == s[::-1]

def dist_to_next_pali(n):
    i = 0;
    N = len(n)
    n = int(n)
    while not palidrome_check(n + i, N):
        i+=1
    return i

if __name__ == "__main__":
    i = input()
    while (i != "0"):
        print(dist_to_next_pali(i))
        i = input()
