def func(w1, w2):
    for letter in w2:
        #print(letter)
        #print(w1)
        if((letter in w1) and (letter != w1[0])):
            #print("break")
            break
        elif((letter in w1) and (letter == w1[0])):
            w1 = w1[1:]
        if len(w1)==0:
            #print(w1)
            return "PASS"
    return "FAIL"

for i in range(0, 27):
    line = input().split()
    #print(line[0])
    #print(line[1])
    #print("abc"[1:])
    print(func(line[0],line[1]))
